#include <iostream>
#include "DIE.h"

// Rules Display
void displayRules() {
    std::cout << "Let's Play PIG Dice!\n";
    std::cout << "* See how many turns it takes you to get to 20 points.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you bank all points for the turn to the game score.\n";
}

// Adds turn score to the total game score
void hold(GameState &g) {
    g.game_score += g.score_this_turn;
    g.turn_over = true;

    if (g.game_score >= 20) {
        g.game_over = true;
    }
}

// Controls one turn
void takeTurn(GameState &g, Die &myDie) {
    g.turn_over = false;
    g.score_this_turn = 0;

    std::cout << "\nTURN " << g.turn_count + 1
              << " - Game Score: " << g.game_score << std::endl;

    while (g.turn_over == false) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> g.choice;

        if (g.choice == 'r' || g.choice == 'R') {
            myDie.roll(g);
        }
        else if (g.choice == 'h' || g.choice == 'H') {
            hold(g);
        }
        else {
            std::cout << "Invalid input. Please enter r or h.\n";
        }
    }

    std::cout << "Score Banked This Turn: "
              << g.score_this_turn << std::endl;

    g.turn_count++;
    g.score_this_turn = 0;
}

// Keeps playing until the score reaches at least 20
void playGame(GameState &g, Die &myDie) {
    while (g.game_over == false) {
        takeTurn(g, myDie);
    }

    std::cout << "\nYou finished with a final score of "
              << g.game_score << " in "
              << g.turn_count << " turns!\n";

    std::cout << "Thanks for playing PIG Dice!\n";
}

int main() {
    GameState my_game;
    Die myDie;

    displayRules();
    playGame(my_game, myDie);

    return 0;
}