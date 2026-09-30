//
// Created by almoa on 9/29/2026.
//
#include "DIE.h"
#include <iostream>
#include <random>

Die::Die() {
    m_numOfSides = 6;
    setValue();
}

// Allows only a 4, 6, or 8 sided die
void Die::setNumOfSides(int numOfSides) {
    switch (numOfSides) {
        case 4:
            m_numOfSides = 4;
            break;
        case 6:
            m_numOfSides = 6;
            break;
        case 8:
            m_numOfSides = 8;
            break;
        default:
            m_numOfSides = 6;
    }
}

void Die::setValue() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, m_numOfSides);

    m_value = distr(gen);
}

// Returns die value
int Die::getValue() {
    return m_value;
}

// Returns the number of sides
int Die::getNumOfSides() {
    return m_numOfSides;
}

// Rolls the die and updates the current turn
void Die::roll(GameState &g) {
    setValue();

    std::cout << "Die: " << getValue();

    if (getValue() == 1) {
        std::cout << "\nTurn over. No score.\n";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn += getValue();
        std::cout << " - Running score this turn: "
                  << g.score_this_turn;
    }

    std::cout << std::endl;
}
