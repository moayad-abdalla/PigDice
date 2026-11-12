#ifndef AABDALLA_PDGAMEV2_H
#define AABDALLA_PDGAMEV2_H

#include "PDGame.h"
#include <string>
#include <vector>

// Inheritance reuses the original game's Turn object and game-over state.
class PDGameV2 : public PDGame {
private:
    // Encapsulation keeps player names and scores inside the game.
    std::vector<std::string> m_playerNames;
    std::vector<int> m_playerScores;

public:
    PDGameV2();

    // Abstraction lets main start the game without managing its details.
    void playGame();

private:
    void displayRules();
    void displayScores() const;
    void displayWinner() const;
};

#endif
