    //
    // Created by rodhoda on 1/23/2022.
    //

    #include<string>
    #include<map>
    #include<vector>

    using namespace std;

    class XMLNode {

    private:
        string name;
        map<string, string> properties;
        string content;
        vector<XMLNode*> children;
        string nodeFile;

        // Purpose: Takes a whole string a delimiter and splits it whenever is found
        // Input: A string and a char delimiter
        // Output: A vector of split strings
        vector<string> split (string, char);

        // Purpose: Takes the line of string and formats it into a node.
        // Input: A string
        // Output: XML Node stored in a vector
        XMLNode* parseline(string&);

    public:


        // Purpose: Constructor that takes the file string name in question
        // Input: N/A
        // Output: N/A

        XMLNode();
        XMLNode(string);

        // Purpose: Takes an XML file and parses into nodes, if file not found throw exception
        // Input: The string of the XML filename is sent it
        // Output: Parses the XML file and formats it into nodes in a vector
        void ParseFile(string);

        // Purpose: Takes XML node and writes it to an XML file, if file not found, create file
        // Input: The filename string that is sent through
        // Output: Creates/outputs xml file
        void WriteFile(string);

        // Purpose: Finds the node info based on the node name given
        // Input: Inputs the node string that it search for
        // Output: The properties and value strings of the node that is found
        void FindByNodeType(string);

        // Purpose: Finds the node in which the property and value are stored in
        // Input: Property and value strings
        // Output: The node and it's content strings are printed out into console
        void FindByProperty(string, string);

        // Purpose: Prints out each of the nodes listed in the vector
        // Input: N/A
        // Output: Prints out each Node content into console.
        void PrettyPrintDocument();

        // Purpose: Appends the details of each node and appends to the string parameter
        //          to be sent back
        // Input: Empty String reference variable that is added to through each recursion
        // Output: Returns the string variable that contains node data in xml form
        string WriteFileHelper(string&);

    };

