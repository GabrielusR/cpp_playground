#include <iostream>
#include <stack>

#include "recursion.h"

using std::cout;
using std::stack;

int arraySum( int arr[], int size )
{
    if( size == 0 )
    {
        return 0;
    }

    int sum = arr[ size - 1 ];

    sum += arraySum( arr, size - 1 );

    return sum;
}

int factorial( int num )
{
    if( num == 1 )
    {
        return num;
    }

    return num * factorial( num - 1 );
}

int zeroCount( int arr[], int size )
{
    if( size == 0 ) return 0;

    int count = zeroCount( arr, size - 1 );

    if( arr[ size - 1 ] == 0 ) count += 1;

    return count;
}

int countNegatives( const Node * nodeList )
{
    if( nodeList == nullptr )
    {
        return 0;
    }

    int negatives = countNegatives( nodeList->next );

    if( nodeList->num < 0 )
    {
        negatives += 1;
    }

    return negatives;
}

int findLargestValueRecursive( const TreeNode * tree )
{
    if( tree == nullptr )
    {
        return 0;
    }

    if( tree->left == nullptr
    && tree->right == nullptr )
    {
        return tree->data;
    }

    int largest = tree->data;

    int leftLargest = findLargestValueRecursive( tree->left );
    int rightLargest = findLargestValueRecursive( tree->right );

    if( leftLargest > largest )
    {
        largest = leftLargest;
    }

    if( rightLargest > largest )
    {
        largest = rightLargest;
    }

    return largest;
}

int findLargestValueStacked( const TreeNode * tree )
{
    if( tree == nullptr )
    {
        return 0;
    }

    stack<const TreeNode *> nodes;

    nodes.push( tree );

    int largest = tree->data;

    while( !nodes.empty() )
    {
        const TreeNode * currentNode = nodes.top();

        nodes.pop();

        if( currentNode->left != nullptr )
        {
            int left = currentNode->left->data;

            if( left > largest )
            {
                largest = left;
            }

            nodes.push( currentNode->left );
        }

        if( currentNode->right != nullptr )
        {
            int right = currentNode->right->data;

            if( right > largest )
            {
                largest = right;
            }

            nodes.push( currentNode->right );
        }
    }

    return largest;
}
