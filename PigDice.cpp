#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>



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

    Die() { //deafult constructor
        m_numOfSides = 6;
        setValue();
    }

    // Allows only a 4, 6, or 8 sided die
    void setNumOfSides(int numOfSides) {
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

    void setValue() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, m_numOfSides);
        m_value = distr(gen);
    }

    // Returns die value
    int getValue() {
        return m_value;
    }

    // Returns the number of sides
    int getNumOfSides() {
        return m_numOfSides;
    }

    //Rolls the die and updates the current turn
    void roll (GameState &g) {
        /*srand(time(NULL))
         *int die = rand () %6 +1%; */
        Die myDie; // calls the default constructor
        //myDie.setValue(); // calling the public function to roll the die
        std::cout <<"Die: " << myDie.getValue();
        if (myDie.getValue() == 1) {
            std::cout << "\nTurn over. No score. \n";
            g.score_this_turn = 0;
            g.turn_over = true;
        }
        else {
            g.score_this_turn+=myDie.getValue();
            std::cout << " - Running score this turn: " << g.score_this_turn;
        }
        std::cout << std::endl;
    }
};



// Rules Display
void displayRules() {
    std::cout << "Let's Play PIG Dice!\n";
    std::cout << "* See how many turns it takes you to get to 20 points.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you bank all points for the turn to the game score.\n";
}

//Adds turn score to the total game score
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
            // Invalid input to give player another chance
            std::cout << "Invalid input. Please enter r or h.\n";
        }
    }

    std::cout << "Score Banked This Turn: "
              << g.score_this_turn << std::endl;

    //completed turn increases the turn count
    g.turn_count++;
    g.score_this_turn = 0;
}

//Keeps playing until the score reaches at least 20
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
    GameState my_game; // instantiate a GameState object
    Die myDie; // calls the default constructor

    displayRules();
    playGame(my_game, myDie);

    return 0;
}