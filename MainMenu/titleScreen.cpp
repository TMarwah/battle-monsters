#include <iostream>
#include "MainMenu.h"

int main ()
{
    MainMenu object;
    int choices;
    int Tries {1}; //attempts to add a name
    object.displayMenu();
    do
    {
        std::cout << "\n0. Quit\n1. Names\n\n";
        std::cin >> choices;
        switch (choices)
        {
            case 0:
            {
                object.creditsMenu();
                break;
            }
            case 1:
            {
                object.blankNameMenu();
            }
        }
    }while(choices != 0);
}

// a better implementation would be to use states
// if state is still in "game"... game continues
// if state is in "exit"... game discontinues