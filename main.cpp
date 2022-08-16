#include <string.h>

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

#include "trackstate.h"
#include "input.h"
#include "mode.h"
#include "license.h"
#include "student.h"
#include "multiarray.h"
#include "variablestrings.h"
#include "linkedlist.h"
#include "class.h"
#include "recursion.h"

int main()
{
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

    leftSubTree->right->data = 12;
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

    cout << "The largest value (recursion): " << findLargestValueRecursive( root ) << "\n";

    cout << "The largest value (stack): " << findLargestValueStacked( root ) << "\n";

	return 0;
}

