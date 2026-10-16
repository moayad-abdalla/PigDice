
#ifndef AABDALLA_TURN_H
#define AABDALLA_TURN_H
#include "DIE.h"

class PDGame;

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr;
public:
    Turn();
    void setParentGame(PDGame* parentGame);
    void takeTurn();
    int getScoreThisTurn() const;
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();
private:
    void roll();
};

#endif


