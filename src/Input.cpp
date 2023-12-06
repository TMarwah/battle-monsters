#include "Input.h"
#include <iostream>


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Input::getInput(const GameComponents& gameComponents) {

    std::string p1_name = gameComponents.getPlayers().getPlayer(0).getName();

    switch(getState())
    {
        case PLAYERS_SETUP_ST:
            getPlayersSetupInput();
            break;

        case DRAFT_ST:
            getDraftInput();
            break;

        case BATTLE_ST:
            getBattleInput(gameComponents);
            break;

        case PLAY_AGAIN_ST:
            getPlayAgainInput();
            break;

    }
}


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
Event Input::getEvent() const {
    return _event;

}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
void Input::getPlayersSetupInput() {
    
    // TODO: validate input

    char name1[80];
    char name2[80];

    std::cout << "Player 1 name: ";
    std::cin.getline(name1, 80);

    std::cout << "Player 2 name: ";
    std::cin.getline(name2, 80);

    // set event data
    _event.data1 = name1;
    _event.data2 = name2;
    _event.eventType = EventType::SET_NAMES;

}


void Input::getDraftInput() {

    // TODO: validate input

    char draftSelection[80];

    std::cout << "Draft Selection: ";
    std::cin.getline(draftSelection, 80);

    // set event data
    _event.data1 = draftSelection;
    _event.data2 = "null";
    _event.eventType = EventType::DRAFT_SELECTION;

}


void Input::getBattleInput(const GameComponents& gameComponents) {

    // TODO: validate input

    char attack[80];

    // true = p1's turn
    // false = p2's turn
    bool playerTurn = true;

    const Bench* p1_bench = gameComponents.getPlayers().getPlayer(0).getBench();
    const Bench* p2_bench = gameComponents.getPlayers().getPlayer(1).getBench();

    while(true) {
        // FIXME: Move this part of the code to Display class
        // ==============
        if(p1_bench->getCurrent().isDead() || p2_bench->getCurrent().isDead()) {
            break;
        }
        
        std::cout << "\n\nmoves:\n";
        if(playerTurn) {
            for(unsigned i = 0; i < p1_bench->getCurrent().getMoves().size(); ++i) {
                MoveSet* currentMove = p1_bench->getCurrent().getMoves().at(i);
                std::cout << "\t" << i+1 << ": [" << currentMove->getName() << "] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
            }
            std::cout << "Player1 ";
        }   else {
            for(unsigned i = 0; i < p2_bench->getCurrent().getMoves().size(); ++i) {
                MoveSet* currentMove = p2_bench->getCurrent().getMoves().at(i);
                std::cout << "\t" << i+1 << ": [" << currentMove->getName() << "] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
            }
            std::cout << "Player2 ";
        }
        // ==============
        std::cout << "Select your attack move: ";
        std::cin.getline(attack, 80);

        // set event data
        _event.data1 = attack;
        _event.data2 = "null";
        _event.eventType = EventType::ATTACK;

        playerTurn = !playerTurn;
    }

}


void Input::getPlayAgainInput() {
    
    // TODO: validate input
    // TODO: write less ugly code in here

    char userSelection[80];

    std::cout << "Play Again? (Y/N): ";
    std::cin.getline(userSelection, 80);

    // set event data
    _event.data1 = "null";
    _event.data2 = "null";

    // std::cout << "USER SELECTED " << userSelection << std::endl;

    // FIXED: it is not case sensetive
    if( !strcmp(userSelection, "Y") | !strcmp(userSelection, "y") ) {
        std::cout << "EventType::REPLAY " << std::endl;
        _event.eventType = EventType::REPLAY;
    }
    else if( !strcmp(userSelection, "N") | !strcmp(userSelection, "n") ) {
        std::cout << "EventType::QUIT " << std::endl;
        _event.eventType = EventType::QUIT;

    }

    // std::cin.get();
    // std::cin.ignore(100, '\n');

}