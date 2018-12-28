//#include "GameLogic.h"
//#include "GameUI.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;



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

// generate code lines without hex codes
string* generateCodeLine(int rows, int columns, int nrOfWords, int lenOfWord, string* words)
{
    int size = rows * columns;
    int totalLen = 12; // total length of code line
    string codeLines[size];
    string* codeLinesPtr = codeLines;
    string codeLine;
    int idx = rows / nrOfWords;
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        codeLine = generatePadding(totalLen);
        if (i % idx == 0 && j < nrOfWords)
        {
            codeLine = codeLine.substr(0,totalLen-lenOfWord);
            codeLine += words[j];
            j++;
        }
        codeLines[i] = codeLine;
    }

    return codeLinesPtr;
}


int ROWS = 12;
int COLUMNS = 2;

int main()
{

    string paddings[ROWS];
    int nrOfWords = 3;
    int lenOfWord = 4;
    int size = ROWS * COLUMNS;
    int idx = ROWS / nrOfWords;
    int codeLength = 12;

    string words[] = {"HELL", "LLEH", "EHLL"};

    ///////// GENERATE CODE LINES
    string codeLines[size];
    string codeLine;
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

    // Clear the terminal screen
    system("CLS");      // only for windows

//////////////////////// PRINT HEADER TO SCREEN ///////////////////////////////////////////////////////////////////////////
    // Print screen contents
    int attTotal = 4 ;   // TODO get attempts
    int attLeft = 2;
    string attempts;
    for(int i=0; i < attLeft;i++){ attempts += "[]"; }

    // Print HEADER to the screen
    printf("ROBCO INDUSTRIES (TM) TERMALINK PROTOCOL\nENTER PASSWORD NOW\n\n");
    cout << "ATTEMPT(S) LEFT: " + attempts + "\n" << endl;

//////////////////////// PRINT GAME PUZZLE TO SCREEN ///////////////////////////////////////////////////////////////////////////

    // print contents of HISTORY TODO put history in right place
    list <string> history = {"erster versuch", "2.ter versuch"};

    string wholeLines[ROWS];
    string line;
    for(int i = 0; i < ROWS; i++)
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

    int k = 0;
    cout << wholeLines[k] << "  HISTORY" << endl; k++;
    for(auto v : history)
    {
        cout << wholeLines[k] << "  >" << v << endl;
        k++;
    }

    for(int i = k; i < ROWS; i++)
    { cout << wholeLines[i] << endl; }





	
	return 0;
}