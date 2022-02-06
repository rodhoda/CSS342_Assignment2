#include <fstream>
#include "XMLNode.h"
#include <iostream>
using namespace std;

// Default constructor
XMLNode::XMLNode() {
}

// Parameterized constructor with an initialization list that assigns the file
XMLNode::XMLNode(string filename) {
    this->ParseFile(filename);
}
// Takes the file as a parameter, takes each line from the file, and sends it
// to parseline for it to be parsed.
void XMLNode::ParseFile(string filename) {
    // Using ifstream, it will open the file that's passed in, and is marked
    // to be used for reading purposes
    ifstream file(filename);
    string line;
    // the while loop makes sure to stop once there are no more lines left
    // in the file
    while (!file.eof()) {
        // gets each line from the file, and dividing each line through the
        // \n delimiter
       getline(file, line, '\n');
       // passes the line found in parseline to the parseline function
       parseline(line);
    }
    // If the file was not found, throw and error message
    if (!file.is_open()) {
        cerr << "File not found." << endl;
    }
}

// Takes the file parameter that needs to be filled with xml data
// uses a helper function to gather the data from the stored nodes
void XMLNode::WriteFile(string filename) {
    // Opens the filename parameter through the variable named file.
    // For the purpose of outputting text onto that file
    ofstream file(filename);
    string line;
    // Sends an empty line variable so that the WriteFileHelper function
    // fills the string with the needed info, and stores it back to line.
    line = WriteFileHelper(line);
    //Outputs the line into the file
    file << line;
    // Closes it
    file.close();
}

// Helper function for WriteFile
// Intended to iterate through each node and collect all the associated data.
// Returns back the exact line string that should be outputted to the file.
// Uses a reference variable of line, so that through each recursion, the line
// will have it's changes remain.
string XMLNode::WriteFileHelper(string& line) {
    // Starts from the parent node and collects all its data
    string curName = this->name;
    string curProperty1;
    string curProperty2;
    string curContent;
    // for loop to collect data from the map
    map<string, string> m = this->properties;
    for(auto const&kv : m) {
        curProperty1 = kv.first;
        curProperty2 = kv.second;
    }
    // checks to see if the node has content or not
    if (this->content != "")
        curContent = this->content;
    // Begins to add the data into the line string
    line = line + "<" + curName + " " + curProperty1 + "=" + curProperty2 + ">" + curContent;

    // for loop to verify if the node has sibling-child nodes
    // In other words, if the children vector has more than one
    // element. If found, recursively calls the function with
    // the child node.
    for (auto *child: this->children)
        child->WriteFileHelper(line);
    // Adds the end tag of that node to the line
    line = line + "</" + curName + ">";
    return line;
}

// Finds the node by the node name parameter being sent through
void XMLNode::FindByNodeType(string node) {
    // checks to see if the current node's name matches with the name parameter
    // If found, prints out it's details
    if (this->name == node) {
        cout << "Name of node: " << this->name << endl;
        for(auto const&kv : this->properties)
            cout << "Properties: " << kv.first << "=" << kv.second << endl;
        cout << "Content: " << this->content << endl;
    }
    // for loop to verify if the node has sibling/child nodes
    // If found, recursively calls the function with the child node
    for (auto *child: this->children)
        child->FindByNodeType(node);
}

// Finds the node by the node's property that's stored in the map variable
void XMLNode::FindByProperty(string value, string result) {
    string val1;
    string val2;
    // Gets the map properties values from the current node
    for(auto const&kv : this->properties) {
        val1 = kv.first;
        val2 = kv.second;
    }
    // Checks to see if those property values match the parameters
    // If so, prints out the details of that node
    if (val1 == value && val2 == result)
    {
        cout << "Name of node: " << this->name << endl;
        cout << "Properties: " << val1 << "=" << val2 << endl;
        cout << "Content: " << this->content << endl;
    }
    // for loop to verify if the node has sibling/child nodes
    // If found, recursively calls the function with the child node
    for (auto *child: this->children)
        child->FindByProperty(value, result);
}
// Recursively traverses the vector pointer of nodes and prints the details
// of each node to the console
void XMLNode::PrettyPrintDocument() {
    // Prints out the details of the current node
    map<string, string> firstProperty = this->properties;
    cout << "\n***********************" << endl;
    cout << "Name of node: " << this->name << endl;
    for(auto const&kv : this->properties)
        cout << "\tProperties: " << kv.first << "=" << kv.second << endl;
    cout << "\tContent: " << this->content << endl;
    cout << "***********************" << endl;
    // for loop to verify if the node has sibling/child nodes
    // If found, recursively calls the function with the child node
    for (auto *child: this->children)
        child->PrettyPrintDocument();
}