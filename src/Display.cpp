#include "Display.h"

/*******************************************************************************
* ACCESSORS
*******************************************************************************/
void Display::render(const Player& player1, const Player& player2) const {

    if(checkState(START_UP)) {
        std::cout << "renderStartup()" << std::endl;
    }
    else if(checkState(INIT)) {
        std::cout << "renderInit()" << std::endl;
    }
    else if(checkState(DRAFT)) {
        std::cout << "renderDraft()" << std::endl;
        std::cout << "p1: " << player1.getName() << "\n";
        std::cout << "p2: " << player2.getName() << "\n";
    }
    else if(checkState(BATTLE)) {
        std::cout << "renderBattle()" << std::endl;
    }
    else if(checkState(REPLAY)) {
        std::cout << "renderReplay()" << std::endl;
    }


}