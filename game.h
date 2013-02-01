#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"

using namespace std;

class game
{
    private:
        board m_b;
        player m_p1;
        player m_p2;
        player *m_currPlayer;
        bool m_isComplete;
        bool m_isWon;
        bool m_isDraw;
        bool m_invalidInput;
    public:
        void run();
        void initalize();
        void update();
        void render();
        bool checkWin();
        void switchPlayer();
        bool checkDraw();
};

#endif // GAME_H
