#pragma once

#include <iostream>
#include <string>

class MainMenu
{
    public:
    void displayMenu()
    {
        std::cout << "|===============================|\n";
        std::cout << "|                               |\n";
        std::cout << "|        Battle Monsters        |\n";
        std::cout << "|                               |\n";
        std::cout << "|===============================|\n";
        std::cout << "\n";
    }
    void blankNameMenu()
    {
        std::cout << "Player 1's name: \n";
        std::cout << "Player 2's name: \n";
    }
    // void updatedNameMenu(); //will update current display
    // void draftMenu();   //will update current display
    // void activeDraftMenu();   //will update current display
    // void battleScreenMenu();    //will update current display
    // void endScreenMenu();   //will update current display
    void creditsMenu()
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
};
