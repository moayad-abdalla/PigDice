//
// Created by almoa on 9/29/2026.
//

#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

class Die {
private:
    int m_value;
    int m_numOfSides;

public:
    int m_test;

    Die();

    void setNumOfSides(int numOfSides);
    void setValue();
    int getValue();
    int getNumOfSides();
    void roll(GameState &g);
};

#endif
