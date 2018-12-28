#include <string>
using namespace std;

string generateHexCodes();
string generatePadding(int paddingSize);
string* generateWholeLines(int rows, string* codeLines);
string* generateLines(int size, int rows, int nrOfWords, int lenOfWord, string* words);
void printPuzzle(int attepts, list <string> history);