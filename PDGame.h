#ifndef AABDALLA_PDGAME_H
#define AABDALLA_PDGAME_H

#include "Turn.h"

class PDGame {
protected:
    Turn m_myTurn;
    bool m_gameOver;

private:
    int m_gameScore;

public:
    PDGame();
    int getGameScore() const;
    void playGame();

private:
    void displayRules();
};

#endif


