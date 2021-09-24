#include <iostream>

#include "input.h"

using std::cin;
using std::cout;

int doubleDigit( int digit )
{
    int doubleDigit = digit * 2;

    int checksum = doubleDigit;

    if( doubleDigit >= 10 )
    {
        checksum = 1 + doubleDigit % 10;
    }

    return checksum;
}

int getDigit( char digit )
{
    //ASCII of '0' is 48
    return digit - '0';
}

int input()
{
    //Input Processing
    cout << "Enter the identification number: ";
    char digit = cin.get();

    int evenChecksum = 0;
    int oddChecksum = 0;
    int pos = 1;
    while( digit != '\n' )
    {
        //when id number has even length
        if( pos % 2 != 0 )
        {
            evenChecksum += doubleDigit( getDigit(digit) );
        }
        else
        {
            evenChecksum += getDigit( digit );
        }

        //when id number has odd length
        if( pos % 2 == 0 )
        {
            oddChecksum += doubleDigit( getDigit(digit) );
        }
        else
        {
            oddChecksum += getDigit( digit );
        }

        digit = cin.get();

        pos += 1;
    }

    int checksum = 0;

    //id number is even
    //(pos - 1) discards '\n'
    if( ( pos - 1) % 2 == 0 )
    {
        checksum = evenChecksum;
    }
    else //id number is odd
    {
        checksum = oddChecksum;
    }

    cout << "=========================================\n";
    if( checksum % 10 == 0 )
    {
        cout << "The identification number is valid!\n";
    }
    else
    {
        cout << "The identificaton number is not valid!\n";
    }
    cout << "=========================================\n";

    return 0;
}
