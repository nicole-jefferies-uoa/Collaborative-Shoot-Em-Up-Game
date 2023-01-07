#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include "GameLibrary/GameLibrary.h"
#include "GameLoop.h"

int main()
{
    cout << "\n==================== Program Start ====================\n"
         << endl;

    // The text menu
    TextMenu mr_menu;

    // The game loop
    GameLoop game_loop = GameLoop();

    // The score board
    ScoreBoard bored = ScoreBoard();
    bored.readFromFile("Savefile");

    // Where the user's choice when presented with a menu is stored
    string choice = "not p";

    // Now the fun begins
    while (true)
    {
        if (choice != "p")
        {
            // Draw the main menu
            mr_menu.drawMainMenu(bored.getHighScore());

            // Get the choice of the user
            choice = mr_menu.getMainMenuChoice();
        }

        // If the user wants to quit
        if (choice == "q")
        {
            break;
        }

        // If the user wants to see previous scores
        else if (choice == "s")
        {
            mr_menu.drawLastScores(bored.getLastNScores(5));
            mr_menu.waitForInput();
        }

        // If the user wants to play the game
        else if (choice == "p")
        {
            // Run the game loop
            cout << "\nGame started" << endl;

            game_loop.reset();
            game_loop.runGameLoop();

            cout << "Game ended\n"
                 << endl;

            // Save the score
            bored.addScore(game_loop.lose_frame);

            // Draw the lose menu
            mr_menu.drawEndMenu(bored.getLastScore(), bored.getHighScore());

            // Get the choice of the USER in a DRAMATIC VOICE
            choice = mr_menu.getEndMenuChoice();

            // If the user wants to quit
            if (choice == "q")
            {
                break;
            }
        }
    }

    // User wants to exit
    cout << "Saving data to file" << endl;
    bored.saveToFile("Savefile");

    cout << "\n===================== Program End =====================\n"
         << endl;

    return 0;
}