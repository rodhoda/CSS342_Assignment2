#include <iostream>
#include "C:\Users\rodho\CLionProjects\Assignment2Work\XMLNode.h"
#include <fstream>
int main() {
//    XMLNode *test1 = new XMLNode;
//    test1->ParseFile("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test.xml");
//    test1->WriteFile("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test3.xml");
////    test1->FindByNodeType("Parent");
////    test1->FindByProperty("name", "Abdi");
//    test1->PrettyPrintDocument();
//    delete test1;


    XMLNode *test1 = new XMLNode;

    // test2("test2.xml");
    test1->ParseFile("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test.xml");
    test1->WriteFile("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test3.xml");
    XMLNode *test3 = new XMLNode("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test3.xml");
    XMLNode *test2 = new XMLNode("C:\\Users\\rodho\\CLionProjects\\Assignment2Work\\test2.xml");
//    test1->FindByNodeType("Child");
//    test1->FindByProperty("name", "other");
//    test1->PrettyPrintDocument();
    test2->PrettyPrintDocument();
//    test3->PrettyPrintDocument();
    return 0;

}
