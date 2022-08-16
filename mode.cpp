#include <iostream>

#include "student.h"
#include "mode.h"

using std::cout;
using std::cin;

void arrayDump( int arr[], int arrSize )
{
    for( int i = 0; i < arrSize; i++ )
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

//simplified insertion sort
void insertionSort( int arr[], int from, int to )
{
    for( int i = from + 1; i <= to; i++ )
    {
        for( int j = i; j > from && arr[j-1] > arr[j]; j-- )
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }
}

bool isSorted( int arr[], int arrSize )
{
    for( int i = 1; i < arrSize; i++ )
    {
        int a = arr[i-1];
        int b = arr[i];

        if( diffFunc(&a, &b) > 0 )
        {
           return false;
        }
    }

    return true;
}

int * findMode( int arr[], int arrSize )
{
    int * result = new int[2];

    int mode = 1;
    int highestFrequency = arr[0];

    for( int i = 1; i < arrSize; i++ )
    {
        if( arr[i] > highestFrequency )
        {
            highestFrequency = arr[i];
            mode = ( i + 1 ); //considering value 1 is stored at index 0
        }
    }

    result[0] = mode;
    result[1] = highestFrequency;

    return result;
}

void mode()
{
    const int MAX_RESPONSE = 10;

    int frequency[MAX_RESPONSE];

    for( int i = 0; i < MAX_RESPONSE; i++ )
    {
        frequency[i] = 0;
    }

    int response = 0;

    cout << "Enter the survey data or -1 to end : ";
    cin >> response;

    while( response != -1 )
    {
        frequency[ response - 1 ] += 1;
        cout << "Enter the survey data or -1 to end : ";
        cin >> response;
    }

    int * result = findMode( frequency, MAX_RESPONSE );

    int mode = result[0];
    int highestFrequency = result[1];

    delete [] result;

    cout << "The mode is : " << mode << "\n";
    cout << "The number of occurences is : " << highestFrequency << "\n";
}
