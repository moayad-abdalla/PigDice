#include "Turn.h"
#include <iostream>

using namespace std;

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = 'r';
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

    cout << "Die: " << value;

    if (value == 1) {
        m_scoreThisTurn = 0;
        m_turnOver = true;
        cout << "\nTurn over. No score.\n";
    } else {
        m_scoreThisTurn += value;
        cout << " - Running score this turn: "
             << m_scoreThisTurn << '\n';
    }
}

void Turn::takeTurn() {
    ++m_turnCount;
    resetScoreThisTurn();
    resetTurnOver();

    while (!m_turnOver) {
        cout << "roll or hold? (r/h): ";

        if (!(cin >> m_choice)) {
            m_turnOver = true;
            m_scoreThisTurn = 0;
            return;
        }

        if (m_choice == 'r' || m_choice == 'R') {
            roll();
        } else if (m_choice == 'h' || m_choice == 'H') {
            m_turnOver = true;
        } else {
            cout << "Enter r or h.\n";
        }
    }

    cout << "Score Banked This Turn: " << m_scoreThisTurn << '\n';
}

