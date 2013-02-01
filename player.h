#include <string>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class player
{
    private:
        string name;
        char icon;
    public:
        void SetName (string n);
        void SetIcon (char i);
        string GetName();
        char GetIcon();
        int getMove();

};

#endif // PLAYER_H1
11
d
