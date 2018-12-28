#include <list>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "GameUI.h"
#include "GameLogic.h"
using namespace std;

int ROWS = 12;
int COLUMNS = 2;

int main()
{
    string words[] = {"HELL", "LLEH", "EHLL"};  // TODO get words from big list of words
    int nrOfWords = 3;
    int lenOfWord = 4;
    GameLogic logic(nrOfWords, lenOfWord, "HELL");


//////////////////////// GENERATE CODE LINES ///////////////////////////////////////////////////////////////////////////
    int size = ROWS * COLUMNS;
    int idx = ROWS / nrOfWords;
    int codeLength = 12;
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

////////////////////////// PRINT CONTENTS TO SCREEN ///////////////////////////////////////////////////////////////////////////

    list <string> history = {};
    string guess;

    do
    {
        printf("ROBCO INDUSTRIES (TM) TERMALINK PROTOCOL\nENTER PASSWORD NOW\n\n"); // Print HEADER to the screen
        string attemptS;
        for (int i = 0; i < logic.attempts; i++) { attemptS += "[]"; }
        cout << "\nATTEMPT(S) LEFT: " + attemptS + "\n" << endl;

        for(int i = 0; i < ROWS; i++) { cout << wholeLines[i] << endl; } // print GUI (hexCodes+codeLines+words)

        printf("\nHISTORY:\n");   // display history
        for(auto v : history) { cout << v << endl; }

        cout << "> "; cin >> guess; cout << "\n\n"; // get next guess from user input
        history.push_back(guess);

        if (logic.check(guess)) { printf("Access granted!"); break; }
        else { logic.attempts--; }

        system("CLS");
    }while (logic.attempts != 0);

//////////////// Print GUI one last time before ending game ////////////////////////////////////////////////////////////
    system("CLS");
    printf("ROBCO INDUSTRIES (TM) TERMALINK PROTOCOL\nENTER PASSWORD NOW\n\n"); // Print HEADER to the screen
    string attemptS;
    for (int i = 0; i < logic.attempts; i++) { attemptS += "[]"; }
    cout << "\nATTEMPT(S) LEFT: " + attemptS + "\n" << endl;

    for(int i = 0; i < ROWS; i++) { cout << wholeLines[i] << endl; } // print GUI (hexCodes+codeLines+words)

    printf("\nHISTORY:\n");   // display history
    for(auto v : history) { cout << v << endl; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if (logic.attempts == 0) { printf("\nYou lost! :'("); }
    else { printf("\nYou craked the code, congratulations! :-) "); }

    printf("\n\n Press enter to exit.");
    cin.ignore();cin.ignore();

    return 0;

}