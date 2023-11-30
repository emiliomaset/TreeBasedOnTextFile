// Name: Your Name
// File Name: tree.h
// Date: 7 Nov, 2023
// Program Description: Header file for C++ program to construct a tree of words from a text file

using namespace std;

struct Node {
    string word;
    int frequencyOfWord;
    Node* left;
    Node* right;
};

template <class Type>
class Tree {
private:
    Type* root;


public:
    Tree();
    ~Tree();
    Type* getRoot();
    void setRoot(Type* root);
    void destroy(Type* root);
    Type* insertBST(Type* root, string insertWord);
    Type* deleteBST(Type* root, string target);
    int getCountOfNodes(Type* root);
    void displayAtoZ(Type* root);
    void displayZtoA(Type* root);
    bool isEmpty(Type* root);
    int getHeight(Type* root);
    bool isFull(Type* root);
    bool isBalanced(Type* root);
};
