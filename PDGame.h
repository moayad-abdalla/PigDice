
#ifndef AABDALLA_PDGAME_H
#define AABDALLA_PDGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;

public:
    PDGame();
    int getGameScore() const;
private:
    void displayRules();
    void playGame();
};

#endif


