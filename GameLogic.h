#include <string>

using namespace std;

class GameLogic
{
	public:
    string password;
	int nrOfWords, lenOfWord;
    int attempts = 4;

    GameLogic(int nrOfWords, int lenOfWord, string pw)
    {
        password = pw;
    }

    bool check(string guess);

//	string wordSelection();
//	bool computeSimilarity(string a, string b, float threshold);

};