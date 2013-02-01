#include "game.h"
#include <iostream>

void game::initalize() {
    cout << "COMPUTER: \n\n\tInitializing variables..." <<endl;
    m_b.initialize();
    m_p1.SetName("Austin Powers");
    m_p1.SetIcon('+');
    m_p2.SetName("Dr. Evil");
    m_p2.SetIcon('-');
    m_currPlayer = &m_p1;
    cout << "\tLoading complete... \n\n\nInterface is now ready for use." <<endl;
}

void game::run() {
    while (!m_isComplete) {
        render();
        update();
   }
}

void game::update() {
    m_isWon = checkWin();
    m_isDraw = checkDraw();
    m_isComplete = (m_isDraw || m_isWon);
    if (!m_isComplete) {
        cout << "Computer: Your move?...\t";
        m_invalidInput = m_b.update(m_currPlayer->getMove(),m_currPlayer->GetIcon());
        while (!m_invalidInput) {
            cout << "Invalid move, please try again: ";
            m_invalidInput = m_b.update(m_currPlayer->getMove(),m_currPlayer->GetIcon());
        }
        switchPlayer();
    }
    else if (m_isWon){
        switchPlayer();
        cout << "You win!!! " <<m_currPlayer->GetName() << " ("<<m_currPlayer->GetIcon() << ")\n"<<endl;
        switchPlayer();
        cout <<m_currPlayer->GetName() << " ("<<m_currPlayer->GetIcon() << ")" << " is defeated."<<endl;
    }
    else if (m_isDraw)
        cout << "\n\n\nIt's a draw" <<endl;
}

void game::render() {
    if (!m_isComplete) {
        cout << "\nTo play: "<<m_currPlayer->GetName() << " ("<<m_currPlayer->GetIcon() << ")"<<endl;
        m_b.render();
    }
}

bool game::checkWin() {
    int l = 0, m = 0, n = 0;
    for (int j = 0; j < 6 ; j++) {
        if (((m_b.pBox[l]) == (m_b.pBox[l+1])) && ((m_b.pBox[l]) == (m_b.pBox[l+2]))) return true;
        else l+=3;
        if (((m_b.pBox[m]) == (m_b.pBox[m+3])) && ((m_b.pBox[m]) == (m_b.pBox[m+6]))) return true;
        else m++;
    }
    for (int k = 0; k < 2; k++ ) {
        if (((m_b.pBox[n]) == (m_b.pBox[4])) && ((m_b.pBox[n]) == ((m_b.pBox[8-n])))) return true;
        else n+=2;
    }
    return false;
}

void game::switchPlayer() {
    if (m_currPlayer == &m_p1)
        m_currPlayer = &m_p2;
    else
        m_currPlayer = &m_p1;
}

bool game::checkDraw() {
    int fillCount = 0;
    for (int i = 0; i < 9; i++) {
        if (!isdigit(m_b.pBox[i]))
            fillCount+=1;
    }
    if (fillCount == 9)
        return true;
    else
        return false;
}
