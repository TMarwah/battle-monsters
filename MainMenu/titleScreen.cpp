#include <iostream>
#include "MainMenu.h"

int main ()
{
    MainMenu object;
    int choices;
    object.renderTitle();
    // do
    // {
        std::cout << "\n0. Quit\n1. Names\n2. Play Game\n3. _testEndScreen \n\n";
        std::cin >> choices;
        switch (choices)
        {
            case 0:
            {
                object.renderCredits();
                break;
            }
            case 1:
            {
                object.renderBlankNames();
                //make it so i can input names
                //make it so i can edit names
                //make a confirmation message
                break;
            }
            case 2:
            {
                object.draftMenu();
                break;
            }
            case 3:
            {
                object.renderEndScreen();
                break;
            }
        }
    // }while(choices != 0);
}

// a better implementation would be to use states
// if state is still in "game"... game continues
// if state is in "exit"... game discontinues