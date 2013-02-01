#ifndef BOARD_H
#define BOARD_H

using namespace std;

class board
{
    private:
        char box[9];
    public:
        void initialize();
        void render();
        bool update(int move,char icon);
        char* pBox;
};

#endif // BOARD_H
