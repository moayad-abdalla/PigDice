#include <iostream>
#include <ctime>
#include <cstdlib>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);
void display_rules();

int main() {
    GameState my_game;

    display_rules();

    play_game(my_game);

    return 0;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!" << std::endl;
}

void play_game(GameState &g) {
    while (!g.game_over) {
        take_turn(g);

        g.game_score += g.score_this_turn;

        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }

    std::cout << "You finished with a final score of ";
    std::cout << g.game_score;
    std::cout << " in " << g.turn_count << " turns! ";
    std::cout << "\nThanks for playing PIG Dice!";
}

void take_turn(GameState &g) {
    g.turn_count++;

    std::cout << "\nTURN " << g.turn_count;
    std::cout << " - Game Score: " << g.game_score << std::endl;

    while (!g.turn_over) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> g.choice;

        if (g.choice == 'r') {
            roll(g);
        }
        else if (g.choice == 'h') {
            hold(g);
        }
        else {
            std::cout << "Invalid Choice!" << std::endl;
        }
    }

    std::cout << "Score Banked This Turn: "
              << g.score_this_turn << std::endl;
}

void roll(GameState &g) {
    srand(time(NULL));

    int die = rand() % 6 + 1;

    std::cout << "Die: " << die;

    if (die == 1) {
        std::cout << std::endl;
        std::cout << "Turn over. No Score." << std::endl;

        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn += die;

        std::cout << " - Running score this turn: "
                  << g.score_this_turn << std::endl;
    }
}

void hold(GameState &g) {
    g.turn_over = true;


}