#include "variablestrings.h"

int length( arrayString str )
{
    int length = 0;

    while( str[length] != '\0' )
    {
        length += 1;
    }

    return length;
}

char characterAt( char * str, int pos )
{
    return str[pos];
}

void append( arrayString & str, char character )
{
    int strSize = length( str );

    char * newStr = new char[strSize+2];

    for( int i = 0; i < strSize; i++ )
    {
        newStr[i] = str[i];
    }

    newStr[strSize] = character;
    newStr[strSize+1] = '\0';

    delete [] str;

    str = newStr;
}

void concatenate( arrayString & str, arrayString str2 )
{
    int strSize = length( str );
    int strSize2 = length( str2 );

    char * newStr = new char[strSize+strSize2+1];

    for( int i = 0; i < strSize; i++ )
    {
        newStr[i] = str[i];
    }

    for( int i = 0; i < strSize2; i++ )
    {
        newStr[strSize+i] = str2[i];
    }

    newStr[strSize+strSize2] = '\0';

    delete [] str;

    str = newStr;
}
