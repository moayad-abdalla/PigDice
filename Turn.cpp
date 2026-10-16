#include "Turn.h"
#include "PDGame.h"
#include <iostream>

using namespace std;

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = 'r';
}

void Turn::setParentGame(PDGame* parentGame) {
    m_parentGame = parentGame;
}
int Turn::getScoreThisTurn() const {
    return m_scoreThisTurn;
}


int Turn::getTurnCount() {
    return m_turnCount;
}

void Turn::resetTurnOver() {
    m_turnOver = false;
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void Turn::roll() {
    m_myDie.rollDie();

    int value = m_myDie.getDieValue();

    cout << "You rolled a " << value << "!\n";

    if (value == 1) {
        m_scoreThisTurn = 0;
        m_turnOver = true;
        cout << "You lost the points for this turn.\n";
    } else {
        m_scoreThisTurn += value;
        cout << "Score this turn: "
             << m_scoreThisTurn << '\n';
    }
}

void Turn::takeTurn() {
    ++m_turnCount;
    resetScoreThisTurn();
    resetTurnOver();

    cout << "\nTurn " << m_turnCount << '\n';
    cout << "Game score: "
         << m_parentGame->getGameScore() << '\n';

    while (!m_turnOver) {
        cout << "Roll or hold? (r/h): ";

        if (!(cin >> m_choice)) {
            m_turnOver = true;
            m_scoreThisTurn = 0;
            return;
        }

        if (m_choice == 'r' || m_choice == 'R') {
            roll();
        } else if (m_choice == 'h' || m_choice == 'H') {
            cout << "Score banked this turn: "
                 << m_scoreThisTurn << '\n';
            m_turnOver = true;
        } else {
            cout << "Enter r or h.\n";
        }
    }
}

