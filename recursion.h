#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>

using std::cout;

int arraySum( int arr[], int size );

unsigned long int factorial( int num );

int zeroCount( int arr[], int size );

struct Node
{
    int num;

    Node * next;
};

template <typename T = Node>
T * buildList( int listSize, int defaultValue )
{
    if( listSize == 0 )
    {
        return nullptr;
    }

    Node * node = new T;

    node->num = defaultValue;
    node->next = nullptr;

    T * nodeList = node;

    for( int i = 0; i < (listSize-1); i++ )
    {
        node = new T;

        node->num = defaultValue;
        node->next = nodeList;

        nodeList = node;
    }

    return nodeList;
}

template <typename T = Node>
void cleanList( T * & node )
{
    if( node == nullptr )
    {
        return;
    }

    if( node->next == nullptr )
    {
        delete node;
        node = nullptr;
        return;
    }

    T * lPtr = node;
    T * ptr = node;

    while( ptr != nullptr )
    {
        ptr = ptr->next;

        delete lPtr;

        lPtr = ptr;
    }

    node = nullptr;
}

template <typename T = Node>
void dumpList( const T * node )
{
    if( node == nullptr )
    {
        cout << "Lista passada vazia.\n";

        return;
    }

    const T * ptr = node;

    while( ptr != nullptr )
    {
        cout << "Node: " << ptr->num << "\n";

        ptr = ptr->next;
    }
}

int countNegatives( const Node * nodeList );

struct TreeNode
{
    int data;

    TreeNode * left;
    TreeNode * right;
};

/*
 ===== Frozen Client Code =====
    TreeNode * root = new TreeNode;

    root->data = 1;
    root->left = new TreeNode;
    root->right = new TreeNode;

    TreeNode * leftSubTree = root->left;

    leftSubTree->data = 3;
    leftSubTree->left = new TreeNode;
    leftSubTree->right = new TreeNode;

    leftSubTree->left->data = 5;
    leftSubTree->left->left = nullptr;
    leftSubTree->left->right = nullptr;

    leftSubTree->right->data = 6;
    leftSubTree->right->left = new TreeNode;

    leftSubTree->right->left->data = 10;
    leftSubTree->right->left->left = nullptr;
    leftSubTree->right->left->right = nullptr;

    leftSubTree->right->right = nullptr;


    TreeNode * rightSubTree = root->right;

    rightSubTree->data = 9;
    rightSubTree->left = new TreeNode;
    rightSubTree->right = new TreeNode;

    rightSubTree->left->data = 11;
    rightSubTree->left->left = nullptr;
    rightSubTree->left->right = nullptr;

    rightSubTree->right->data = 7;
    rightSubTree->right->left = nullptr;
    rightSubTree->right->right = nullptr;

    cout << "The largest value (recursion): " << findLargestValueRecursive( root );

    cout << "The largest value (stack): " << findLargestValueStacked( root );
*/

//Use client code above to build the tree
int findLargestValueRecursive( const TreeNode * tree );

int findLargestValueStacked( const TreeNode * tree );

#endif
