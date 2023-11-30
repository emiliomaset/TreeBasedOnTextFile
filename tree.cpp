// Name: Your Name
// File Name: tree.cpp
// Date: 7 Nov, 2023
// Program Description: Source file for C++ program to construct a tree of words from a text file

#include <iostream>
#include "tree.h"

template <class Type>
Tree<Type>::Tree() {
    root = NULL;
}

// =========================================================================================================================

template <class Type>
Tree<Type>::~Tree() {
    if (root == NULL)
        return;

    destroy(root->left);
    destroy(root->right);

    delete root;
}

// =========================================================================================================================

template <class Type>
Type* Tree<Type>::getRoot() {
    return root;
}

// =========================================================================================================================

template <class Type>
void Tree<Type>::setRoot(Type *root) {
    this->root = root;
}

// =========================================================================================================================

template <class Type>
void Tree<Type>::destroy(Type *root) {
    if (root == NULL) {
        return;
    }

    destroy(root->left);
    destroy(root->right);

    delete root;
}

// =========================================================================================================================

template <class Type>
Type* Tree<Type>::insertBST(Type *root, string insertWord) {
    if (root == NULL)
    {
        root = new Type;
        root->word = insertWord;
        root->left = root->right = NULL;
        root->frequencyOfWord++;
        return root;
    }

    else if (insertWord == root->word) { // if the word being inserted already exists in the tree, just increment count and return
        root->frequencyOfWord++;
        return root;
    }

    else if (insertWord < root->word)
        root->left = insertBST(root->left, insertWord);

    else if (insertWord > root->word)
        root->right = insertBST(root->right, insertWord);

    return root;
}

// =========================================================================================================================

template <class Type>
Type* Tree<Type>::deleteBST(Type* root, string target)
{
    if (root == NULL)
        return NULL;

    else if (target < root->word)
        root->left = deleteBST(root->left, target);

    else if (target > root->word)
        root->right = deleteBST(root->right, target);

    else {
        if (root->right == NULL) {
            Type *temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        else if (root->left == NULL) {
            Type *temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        else {
            Type *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->word = temp->word;

            return deleteBST(root->right,temp->word);
        }
    }

    return root;
}


// =========================================================================================================================

template <class Type>
int Tree<Type>::getCountOfNodes(Type* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + getCountOfNodes(root->left) + getCountOfNodes(root->right);
}

// =========================================================================================================================

template <class Type>
void Tree<Type>::displayAtoZ(Type *root) {
    if (root != NULL) {

        if (root->left != NULL)
            displayAtoZ(root->left);

        cout << root->word << " (" << root->frequencyOfWord << ") ";

        if ((root->right != NULL))
            displayAtoZ(root->right);
    }

    else
        cout << "Tree is empty!";
}

// =========================================================================================================================

template <class Type>
void Tree<Type>::displayZtoA(Type* root) {
    if (root != NULL) {

        if (root->right != NULL)
            displayZtoA(root->right);

        cout << root->word << "(" << root->frequencyOfWord << ") ";

        if (root->left != NULL)
            displayZtoA(root->left);
    }

    else
        cout << "Tree is empty!";
}

// =========================================================================================================================

template <class Type>
bool Tree<Type>::isEmpty(Type* root) {
    return (root == NULL);
}

// =========================================================================================================================

template <class Type>
int Tree<Type>::getHeight(Type* root) {
    if (root == NULL)
        return 0;

    int heightOfLeftSubtree = getHeight(root->left);
    int heightOfRightSubtree = getHeight(root->right);

    return max(heightOfLeftSubtree, heightOfRightSubtree) + 1; // +1 to account for root
}

// =========================================================================================================================

template <class Type>
bool Tree<Type>::isFull(Type* root) {
    if (root == NULL)
        return true;

    else if (root->left == NULL && root->right == NULL) // if leaf node
        return true;

    else if ( (root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL) ) // if not leaf node or internal node with two children,
                                                                                                           // this is not a full tree
        return false;

    return isFull(root->left) && isFull(root->right);
}

// =========================================================================================================================

template <class Type>
bool Tree<Type>::isBalanced(Type* root) {
    return ( abs(getHeight(root->left) - getHeight(root->right)) == 1 || abs(getHeight(root->left) - getHeight(root->right)) == 0 );
}

// =========================================================================================================================