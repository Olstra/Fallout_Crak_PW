#include <string>
#include <iostream>

#include "GameLogic.h"

using namespace std;


bool GameLogic::check(string guess) {

    string pw = GameLogic::password;

    if(guess.length() != pw.length()) { cout << "Wrong length!"; }
    if (guess == pw) { return true; }
    else{ } // TODO x out of y correct

    return false;
}

