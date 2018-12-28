#include <string>
#include <list>
#include <iostream>
#include "GameUI.h"
using namespace std;


// This functions are work in progress

void printPuzzle(int attepts, list <string> history)
{
//    Clear the terminal screen
//    system("CLS");      // only for windows
    string attemptS;
    for (int i = 0; i < attepts; i++) { attemptS += "[]"; }
    cout << "\nATTEMPT(S) LEFT: " + attemptS + "\n" << endl;
    cout << "HISTORY:\n";
    for(auto v : history) { cout << v << endl; }
}

string* generateLines(int size, int rows, int nrOfWords, int lenOfWord, string* words)
{
    string codeLines[size];
    string* linesPtr = codeLines;
    int codeLength = 12; //TODO generalize Codelength since used in multiple functions
    string codeLine;
    int idx = rows / nrOfWords;

    int j = 0;
    for(int i = 0; i < size; i++)
    {
        codeLine = generatePadding(codeLength);
        if (i % idx == 0 && j < nrOfWords)
        {
            codeLine = codeLine.substr(0,codeLength-lenOfWord);
            codeLine += words[j];
            j++;
        }
        codeLines[i] = codeLine;
    }

    return linesPtr;
}

string* generateWholeLines(int rows, string* codeLines)
{
    string wholeLines[rows];
    string* wLinesPtr = wholeLines;
    string line;
    for(int i = 0; i < rows; i++)
    {
        line += generateHexCodes();
        line += " ";
        line += codeLines[i];
        line += "  ";
        line += generateHexCodes();
        line += " ";
        line += codeLines[i+1];

        wholeLines[i] = line;
        line = "";
    }

    return wLinesPtr;
}

////////////////////////// This functions are OK////////////////////////////////////////////////////////////////////////
string generateHexCodes()
{
    char hexChars[] = "0123456789ABCDEF";
    int len = sizeof(hexChars)-1;           // -1 for taking out the end of string "/0" char

    string hexCode; char randChar;
    hexCode = "0x";             // start of hex code is the same for all codes
    for (int j = 0; j < 4; j++)
    {   randChar = hexChars[rand()%len];
        hexCode += randChar;    }

    return hexCode;
}

string generatePadding(int paddingSize)
{
    char paddingChars[] = "<>[]{}()'|\\\"!@#$%^&*-_+=.;:?,/";
    string s;

    for(int i=0; i < paddingSize; i++)
    { s += paddingChars[rand() % sizeof(paddingChars)-1]; }

    return s;
}