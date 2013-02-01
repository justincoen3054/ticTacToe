#include "player.h"
#include <string>
#include <iostream>

void player::SetName (string n) {
    name = n;
}

void player::SetIcon (char i) {
    icon = i;
}

string player::GetName() {
    return name;
}

char player::GetIcon() {
    return icon;
}

int player::getMove() {
    int move = 0;
    cin >> move;

    if ((cin.fail()) || (move > 9 || move < 1)) {
        cout << "Invalid move, please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> move;
        cout <<endl;
    }
    return move;
}
