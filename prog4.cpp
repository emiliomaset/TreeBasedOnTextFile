// Name: Your Name
// File Name: prog4.cpp
// Date: 7 Nov, 2023
// Program Description: Driver file for C++ program to construct a tree of words from a text file


#include <iostream>
#include <fstream>
#include "tree.cpp"

using namespace std;

ifstream loadFile();
void buildTree(Tree<Node> &myTree, ifstream &inFile);

int main() {
    Tree<Node> myTree;
    ifstream inFile;
    int menuChoice = -1;

    while (menuChoice != 5) {
        cout << "\n1. Build the tree\n" << "2. Display the words (A-Z)\n" << "3. Display the words (Z-A)\n" << "4. Destroy the Tree\n"
             << "5. Exit\n\n" << "Enter your choice: ";

        cin >> menuChoice;
        cout << endl;

        switch (menuChoice) {
            case 1:
                inFile = loadFile(); // load file into inFile
                buildTree(myTree, inFile); // build the tree one word at a time while reading in from file
                cout << "\nThe tree has " << myTree.getCountOfNodes(myTree.getRoot()) << " words and a height of " << myTree.getHeight(myTree.getRoot()) << ".\n";
                if (myTree.isFull(myTree.getRoot()))
                    cout << "The tree is full.\n";
                else
                    cout << "The tree is not full.\n";

                if (myTree.isBalanced(myTree.getRoot()))
                    cout << "The tree is balanced.\n";
                else
                    cout << "The tree is not balanced.\n";
                break;

            case 2:
                myTree.displayAtoZ(myTree.getRoot());
                cout << endl;
                break;

            case 3:
                myTree.displayZtoA(myTree.getRoot());
                cout << endl;
                break;

            case 4:
                if (myTree.getRoot() == NULL)
                    cout << "Tree is empty!\n";
                else {
                    myTree.destroy(myTree.getRoot());
                    myTree.setRoot(NULL);
                    cout << "Tree destroyed!\n";
                }
                break;

            case 5:
                cout << "Goodbye!";
                break;

            default:
                cout << "Invalid menu option entered!\n";
        }
    }
    return 0;
} // end of main

// ======================================================================================================================================================

ifstream loadFile() {
    ifstream inFile;

    string fileName;
    cout << "Enter your file name: ";
    cin >> fileName;

    inFile.open(fileName);

    if (!inFile) {
        cout << "\nThere has been an error opening your file";
        exit(0);
    }

    return inFile; // return ifstream object to inFile in main
}

// ======================================================================================================================================================

void buildTree(Tree<Node> &myTree, ifstream &inFile) {
    /*
    string textToBeEvaluated;
    getline(inFile, textToBeEvaluated);

    char* textToBeEvaluatedCString = new char [textToBeEvaluated.length() - 1]; // i wanted to use this tactic to read the text file into a string instead of
                                                                                hardcoding the char array size, but a weird character is read and placed into the tree.
                                                                                I tried to print the ascii value of this character, but nothing would print.
    strcpy(textToBeEvaluatedCString, textToBeEvaluated.c_str());
     */


    char textToBeEvaluated[372];
    inFile.getline(textToBeEvaluated, 372);

    char *token = strtok(textToBeEvaluated, " ,.-"); // tokenize string to get individual words

    //char* token = strtok(textToBeEvaluatedCString, " ,.-");

    while (token != NULL) {
        if (isupper(token[0])) // if the first letter for the word is uppercase, make it lowercase
            token[0] = tolower(token[0]);

        myTree.setRoot(myTree.insertBST(myTree.getRoot(), token)); // add the word to the tree
        token = strtok(NULL, " ,.-");
    }

}
