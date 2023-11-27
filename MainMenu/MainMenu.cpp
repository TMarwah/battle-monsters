#include "MainMenu.h"
// #include "Game.h"
// #include "Player.h"
// #include "States.h"
#include <string>

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::renderTitle() const
{
    std::cout << "|===============================|\n";
    std::cout << "|                               |\n";
    std::cout << "|        Battle Monsters        |\n";
    std::cout << "|                               |\n";
    std::cout << "|===============================|\n";
    std::cout << "\n";
}

void MainMenu::renderBlankNames() const
{
    std::cout << "Player 1's name: \n";
    std::cout << "Player 2's name: \n\n";
}

// void MainMenu::updatedNameMenu()
// {

// }

/*----------DRAFT FUNCTIONS AND VARIABLES----------*/

// void MainMenu::draftMenu()  //function 1
// {

//     //before:
//     //      |(0,1)|
//     std::string space [1][3] = {{"0", "1", "0"}};
//     //after:
//     // (1,0)|     |(1,2)
//     //std::string space [1][3] = {{"0", "0", "0"}};

//     //this is placeholder
//     std::string n1; // <<player1
//     std::string n2; // <<player2
//     std::cout << "Enter the name of the first player: \n";
//     std::cin >> n1;
//     std::cout << "Enter the name of the second player: \n";
//     std::cin >> n2;
//     std::cout << n1 << " is player1 so he/she will choose first \n";
//     std::cout << n2 << " is player2 so he/she will choose second \n\n";

//     std::cout << "==|===========================================|== \n";
//     std::cout << "  |                                           |   \n";
//     std::cout << "  | PLAYER1                           PLAYER2 |   \n";
//     std::cout << "  |-------------------------------------------|   \n";
//     std::cout << "  |                                           |   \n";
//     std::cout << "  |        " << space[0][0] << "        |   " << space[0][1] << "   |        " << space[0][2] << "        |  \n";
//     std::cout << "  |                                           |   \n";
//     std::cout << "==|===========================================|== \n";
//     std::cout << "\n";
//     std::cout << "|=|===================|=|\n";
//     std::cout << "|=|                   |=|\n";
//     std::cout << "|=|  1.Monster1       |=|\n";
//     std::cout << "|=|                   |=|\n";
//     std::cout << "|=|===================|=|\n";
//     std::cout << "\n";
// }

// void MainMenu::activeDraftMenu()    //function 2
// {}
void MainMenu::renderEndScreen()    //make it so it can take in a name
{
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|       <getName> is Victorious!        \n";
    std::cout << "|                                      |\n";
    std::cout << "|           Play Again (Y/N)           |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";
}
void MainMenu::renderCredits() const
{
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|          Thanks for playing :)       |\n";
    std::cout << "|                                      |\n";
    std::cout << "|             Stanley Zhang            |\n";
    std::cout << "|              William Kim             |\n";
    std::cout << "|             Andrew Tilles            |\n";
    std::cout << "|             Tanmay Marwah            |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";
}
