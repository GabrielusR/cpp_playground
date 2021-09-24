#include <iostream>
#include <string>

#include "trackstate.h"

using std::cin;
using std::cout;
using std::string;

int charToInt( string character )
{
    int charInt = character.at(0) - '0';

    for( int i = 1; i < character.size(); i++ )
    {
        int ch = character.at(i) - '0';

        int tmp = charInt * 10;

        charInt = ( tmp + ch );
    }

    return charInt;
}

char decode( string character, DecodingMode &mode )
{
    const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

    if( mode == UC )
    {
        int charInt = charToInt( character ) % 27;

        if( charInt == 0 )
        {
            mode = LC;
            return '0';
        }
        else
        {
            return charInt + ('A' - 1);
        }
    }
    else if( mode == LC )
    {
        int charInt = charToInt( character ) % 27;

        if( charInt == 0 )
        {
            mode = PCT;
            return '0';
        }
        else
        {
            return charInt + ('A' - 1);
        }
    }
    else if( mode == PCT )
    {
        int charInt = charToInt( character ) % 9;

        return punctuation[ charInt - 1 ];
    }

    return '0';
}

int trackState()
{
    cout << "====================== Message Decoder ============================\n";
    cout << "Enter your encoded message using comma separated encoded characters\n\n";

    //TEST: HELLO WORLD!
    //35,32,39,39,42,27,27,14,27,50,42,45,39,31,27,27,10

    char encodedCharacter;

    encodedCharacter = cin.get();


    DecodingMode mode = UC;


    string decodedCharacter = "\0";
    string decodedMessage = "\0";

    while( encodedCharacter != '\n' || decodedCharacter != "" )
    {
        if( encodedCharacter != ',' && encodedCharacter != '\n' )
        {
            decodedCharacter += encodedCharacter;
        }

        if( encodedCharacter == ',' || encodedCharacter == '\n' )
        {
            if( decode( decodedCharacter, mode ) != '0' )
            {
                decodedMessage += decode( decodedCharacter, mode );
            }

            if( encodedCharacter == '\n' )
            {
                break;
            }

            decodedCharacter = "";
        }

        encodedCharacter = cin.get();
    }


    cout << decodedMessage;

    return 0;
}
