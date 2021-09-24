#ifndef TRACKSTATE_H_
#define TRACKSTATE_H_

#include <string>

using std::string;

//UC = Uppercase, LC = Lowercase, PCT = Punctuation
enum DecodingMode
{
    UC=1,LC,PCT
};

//EXCL = Exclamation, INTG = Interrogation, DQUOTE/SQUOTE = Double/Single Quote
enum Punctuation
{
    EXCL=1, INTG, COMMA, DOT, SPACE, SEMICOLON, DQUOTE, SQUOTE
};

int charToInt( string character );

char decode( string character, DecodingMode &mode );

int trackState();

#endif
