#include "XMLNode.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


/*********************************************************
 * Input: 2 Strings - First is the string to split, second is the delimiter
 * Output:  A vector of the split string components
 * Purpose:  splits a string into parts based on a delimiter
 * ******************************************************/

vector<string> XMLNode::split (string line, char delimiter) {

    vector<string> splitStrings;
    int start = 0;
    int end = line.find(delimiter);
//    cout << start << ", " << end << endl;
    while (end != string::npos ) {
        string subs = line.substr(start, end-start);
//        cout << subs << endl;
        start = end+1;
        end = line.find(delimiter, start);
//        cout << "start: " << start << endl;
//        cout << "end: " << end << endl << endl;
        splitStrings.push_back(subs);
    }
    string subs = line.substr(start, line.length()-start);
//    cout << subs << endl;
    splitStrings.push_back(subs);

    return splitStrings;
}


/*************************************************
 * Input:  String -- single line from an XML file in the form
 * 		<name [properties]>contents</name>
 * Output:  Node - contents of a node
 * Purpose:  Converts a single line into a node for processing
 **************************************************/



XMLNode* XMLNode::parseline(string& line) {

    // int variable to be used to for find function when removing the content,
    // since that would be from the first index.
    // don't ask why I didn't just use zero, it just made sense at the time
    int startOfLine = 0;
        // Making sure the string parameter is not 0,
        // and therefore mitigates any potential out of range errors
        if (line.length() != 0) {
            int startOfTag = 1;
            int endOfTag = line.find(">");
            string tagString = line.substr(startOfTag, endOfTag - startOfTag);
            if (tagString.length() == 0) {
                return this;
            }
            vector<string> properties;
            properties = split(tagString, ' ');
            for (auto val: properties) {
                vector<string> props = split(val, '=');
                if (props.size() != 2) {    // we know this is the name of the node
                    this->name = props[0];
                } else {    // got an actual property
                    this->properties.insert(pair<string, string>(props[0], props[1]));
                }
            }
            int startOfContent = endOfTag + 1;
            line = line.substr(startOfContent, line.length());
            // creating strings to be used in the find function
            string endNode = "</";
            string openTag = "<";
            // When the first section of the line would be the content, this would be the end point
            // since at the end of every content, there's a "<", which can be used as an identifier.
            int endingContent = line.find('<');
            //If the line starts with "<\", that means we are at the end tag of the parent node,
            // and there we are done.
            while (line.find(endNode) != 0) {
                // This is to check whether the line starts with a new node by looking for "<".
                if (line.find(openTag) == 0) {
                    // a new node object is created to store the child nodes
                    XMLNode* curNode = new XMLNode;
                    // adds the new node to the children vector pointer of the parent node
                    this->children.push_back(curNode);
                    // recursively calls the function with the adjusted line, since the next section
                    // of it would include attributes of a new node
                    curNode->parseline(line);
                }
                // When the next section is the content, the else statement is where it goes.
                else {
                    // the content of the node is being spliced into the string variable named content
                    string content = line.substr(startOfLine, endingContent);
                    // After the content, the next section would the end tag of a node,
                    // This int variable finds the ">" index of that end tag Node
                    int endingNode = line.find('>');
                    // The part of the section that was previously assigned, along with the subsequent
                    // end tag of the node are removed from the line.
                    line = line.substr(endingNode + 1, line.length());
                    // the content is assigned to the curNode's content.
                    this->content = content;
                    // returns the curNode along with all it's details stored.
                    return this;
                }
            }
            return this;
        }
}