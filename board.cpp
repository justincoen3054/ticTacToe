#include "board.h"
#include <iostream>

void board::initialize() {
    int n = 1;
    for (int i = 0; i < 9; i++) {
        box[i] = '0' + n;
        n++;
    }
    pBox = box;
}

void board::render() {
    cout <<endl;
    int n = 0;
    for(int i = 0; i < 6; i++) {
        if ((i == 1) || (i == 3) || (i == 5)) {
            cout << "      "<< box[n]<< " | "<< box[n+1]<< " | "<< box[n+2]<<endl;
            n=n+3;
        }
        if ((i == 1) || (i == 3))
            cout << "     ___|___|___"<<endl;
        else
            cout << "        |   |"<<endl;
    }
    cout <<endl;
}

bool board::update(int m, char i) {
    if (!isdigit(box[m-1]))
        return false;
    else {
        box[m-1] = i;
        return true;
    }
}
