#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;

#include "GameLibrary/ScoreBoard.h"

int main(void)
{
    cout << "Creating scoreboard" << endl;
    ScoreBoard my_scoreboard;

    cout << "Adding in scores" << endl;
    for (int i = 0; i < 10; i++)
    {
        my_scoreboard.addScore(rand() % 100);
        cout << "\tAdded score: " << my_scoreboard.getLastScore() << endl;
    }
    cout << endl;

    cout << "High score is: " << my_scoreboard.getHighScore() << endl;
    cout << endl;

    cout << "Saving scores to file 'scoreboard-test'" << endl;
    bool success = my_scoreboard.saveToFile("scoreboard-test");
    cout << "Success = " << success << endl;
    cout << endl;

    cout << "Clearing scoreboard" << endl;
    my_scoreboard.clearScoreBoard();
    cout << "High score is: " << my_scoreboard.getHighScore() << endl;
    cout << "Last score is: " << my_scoreboard.getLastScore() << endl;
    cout << endl;

    cout << "Reading from savefile" << endl;
    my_scoreboard.readFromFile("scoreboard-test");
    cout << "High score is: " << my_scoreboard.getHighScore() << endl;
    cout << "Last score is: " << my_scoreboard.getLastScore() << endl;
    cout << endl;

    cout << "Getting last 4 scores" << endl;
    vector<int> last_4_scores = my_scoreboard.getLastNScores(4);
    cout << "Scores: ";
    for (int i : last_4_scores)
    {
        cout << i << " ";
    }
    cout << endl << endl;

    return 0;
}