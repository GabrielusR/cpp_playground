#ifndef VARIABLESTRINGS_H_
#define VARIABLESTRINGS_H_

typedef char * arrayString;

int length( arrayString str );

//characterAt This function takes a string and a number and returns the character
//at that position in the string (with the first character in the string numbered zero).
char characterAt( char * str, int pos );

//append This function takes a string and a character and appends the character
//to the end of the string.
void append( arrayString & str, char character );

//concatenate This function takes two strings and appends the characters of the
//second string onto the first.
void concatenate( arrayString & str, arrayString str2 );

#endif
