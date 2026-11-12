#include "PDGameV2.h"
#include <iostream>
#include <limits>

using namespace std;

PDGameV2::PDGameV2() {
    int playerCount = 0;

    while (playerCount < 2) {
        cout << "How many people are playing? ";

        if (!(cin >> playerCount)) {
            if (cin.eof()) {
                return;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            playerCount = 0;
        } else {
            string remainingInput;
            getline(cin, remainingInput);

            if (remainingInput.find_first_not_of(" \t\r") != string::npos) {
                playerCount = 0;
            }
        }
        if (playerCount < 2) {
            cout << "Enter a whole number of at least 2.\n";
        }
    }

    int anonymousCount = 0;
    for (int i = 0; i < playerCount; ++i) {
        string name;

        cout << "Enter player " << i + 1 << "'s name: ";

        if (!getline(cin, name)) {
            return;
        }
        if (name.find_first_not_of(" \t\r") == string::npos) {
            ++anonymousCount;
            name = "Anonymous Player " + to_string(anonymousCount);
        }

        m_playerNames.push_back(name);
        m_playerScores.push_back(0);
    }
}

void PDGameV2::displayRules() {
    cout << "\nLet's Play PIG Dice!\n\n";
    cout << "* See which player will reach 50 points in the fewest turns.\n";
    cout << "* Turn ends when you hold or roll a 1\n";
    cout << "* If you roll a 1, you lose all points for the turn.\n";
    cout << "* If you hold, you save all points for the turn.\n";
}
void PDGameV2::displayScores() const {
    cout << '\n';

    for (int i = 0; i < static_cast<int>(m_playerNames.size()); ++i) {
        cout << m_playerNames[i]
             << " (Score:" << m_playerScores[i] << ") | ";
    }
    cout << '\n';
}

void PDGameV2::playGame() {
    if (!cin || m_playerNames.size() < 2) {
        return;
    }

    displayRules();
    int round = 1;

    while (!m_gameOver) {
        for (int i = 0; i < static_cast<int>(m_playerNames.size()); ++i) {
            cout << "\n" << m_playerNames[i]
                 << " (Score:" << m_playerScores[i]
                 << ") - TURN " << round << '\n';

            m_myTurn.takeTurn();

            if (!cin) {
                return;
            }

            m_playerScores[i] += m_myTurn.getScoreThisTurn();
            displayScores();

            if (m_playerScores[i] >= 50) {
                m_gameOver = true;
            }
// Finish the round so every player gets the same number of turns.
        }
        ++round;
    }

    displayWinner();
}

void PDGameV2::displayWinner() const {
    int highestScore = 0;

    for (int score : m_playerScores) {
        if (score > highestScore) {
            highestScore = score;
        }
    }

    int winnerCount = 0;

    for (int score : m_playerScores) {
        if (score == highestScore) {
            ++winnerCount;
        }
    }

    for (int i = 0; i < static_cast<int>(m_playerNames.size()); ++i) {
        if (m_playerScores[i] == highestScore) {
            cout << "\nCongratulations! " << m_playerNames[i];

            if (winnerCount == 1) {
                cout << " you win with a score of ";
            } else {
                cout << " you tie for the win with a score of ";
            }

            cout << highestScore << '\n';
        }
    }
}
