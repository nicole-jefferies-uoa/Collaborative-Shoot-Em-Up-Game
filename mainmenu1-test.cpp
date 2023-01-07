#include "GameLibrary/TextMenu.h"

#include <iostream>

using namespace std;

int main() {
    // CONSTRUCTOR
    TextMenu menu;

    // Draw main menu
    menu.drawMainMenu(56);
    cout << menu.getMainMenuChoice() << endl;

    // Draw end menu
    menu.drawEndMenu(56, 72);
    cout << menu.getEndMenuChoice() << endl;

    return 0;
}
