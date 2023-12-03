#include "Input.h"
#include <iostream>


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Input::getInput(const GameComponents& gameComponents) {

    switch(getState())
    {
        case PLAYERS_SETUP_ST:
            getPlayersSetupInput();
            break;

        case DRAFT_ST:
            getDraftInput();
            break;

        case BATTLE_ST:
            getBattleInput();
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

    // FIXME: when there is empty input '\n' it falls into infintie loop
    // USED GETLINE INSTEAD OF GET + IGNORE
    std::cout << "Player 1 name: ";
    // std::cin.ignore(100, '\n');
    std::cin.getline(name1, 80);


    std::cout << "Player 2 name: ";
    // std::cin.ignore(100, '\n');
    std::cin.getline(name2, 80);
    // std::cin.ignore(100, '\n'); // prevent infinite loop

    // set event data
    _event.data1 = name1;
    _event.data2 = name2;
    _event.eventType = EventType::SET_NAMES;

}


void Input::getDraftInput() {

    // TODO: validate input

    char draftSelection[80];

    std::cout << "Draft Selection: ";
    std::cin.get(draftSelection, 80);
    std::cin.ignore(100, '\n');

    // set event data
    _event.data1 = draftSelection;
    _event.data2 = "null";
    _event.eventType = EventType::DRAFT_SELECTION;

}


void Input::getBattleInput() {

    // TODO: validate input

    char attack[80];

    std::cout << "Select your attack move: ";
    std::cin.get(attack, 80);
    std::cin.ignore(100, '\n');

    // set event data
    _event.data1 = attack;
    _event.data2 = "null";
    _event.eventType = EventType::ATTACK;

}


void Input::getPlayAgainInput() {
    
    // TODO: validate input
    // TODO: write less ugly code in here

    char userSelection[80];

    std::cout << "Play Again? (Y/N): ";
    std::cin.get(userSelection, 80);
    std::cin.ignore(100, '\n');

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