#include "Input.h"
#include <iostream>


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Input::getInput(const GameComponents& gameComponents) {

    // std::string p1_name = gameComponents.getPlayers().getPlayer(0).getName();

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

    std::cout << "\033[1;34mPlayer 1\033[0m name: ";
    std::cin.getline(name1, 80);

    std::cout << "\033[1;35mPlayer 2\033[0m name: ";
    std::cin.getline(name2, 80);

    // set event data
    _event.data1 = name1;
    _event.data2 = name2;
    _event.eventType = EventType::SET_NAMES;

}


void Input::getDraftInput() {

    char p1_choice[80];
    char p2_choice[80];

    std::cout << "\n\n\033[1;34mPlayer 1\033[0m, Select your Monster  >> ";
    std::cin.getline(p1_choice, 80);

    std::cout << "\n\033[1;35mPlayer 2\033[0m, Select your Monster  >> ";
    std::cin.getline(p2_choice, 80);

    // set event data
    _event.data1 = p1_choice;
    _event.data2 = p2_choice;

    // validate input
    if(isValidDraftInput(p1_choice, p2_choice)) {
        _event.eventType = EventType::DRAFT_SELECTION;
    } else {
        _event.eventType = EventType::INVALID_INPUT;
    }

}


void Input::getBattleInput(const GameComponents& gameComponents) {

    char p1_attack[80];
    char p2_attack[80];

    // get user input
    std::cout << "\n\n\033[1;34mPlayer 1\033[0m, Select your move  >> ";
    std::cin.getline(p1_attack, 80);

    std::cout << "\n\033[1;35mPlayer 2\033[0m, Select your move  >> ";
    std::cin.getline(p2_attack, 80);

    // set event data
    _event.data1 = p1_attack;
    _event.data2 = p2_attack;

    // validate input
    if(isValidBattleInput(p1_attack, p2_attack)) {
        _event.eventType = EventType::ATTACK;
    }else {
        _event.eventType = EventType::INVALID_INPUT;
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

}


/*******************************************************************************
* VALIDATORS
*******************************************************************************/
bool Input::isValidDraftInput(const std::string& input1, const std::string& input2) const {
    bool input1Validity = input1 == "1" || input1 == "2" || input1 == "3" || input1 == "4";
    bool inpu21Validity = input2 == "1" || input2 == "2" || input2 == "3" || input2 == "4";

    bool noCoincidence = input1 != input2;

    if(FLAG_ON) {
        std::cout << input1Validity << ", " << inpu21Validity << ", " << noCoincidence << "\n";
    }

    return ( input1Validity && inpu21Validity && noCoincidence );
}

bool Input::isValidBattleInput(const std::string& input1, const std::string& input2) const {
    bool input1Validity = input1 == "1" || input1 == "2";
    bool inpu21Validity = input2 == "1" || input2 == "2";

    if(FLAG_ON) {
        std::cout << input1Validity << ", " << inpu21Validity << "\n";
    }

    return ( input1Validity && inpu21Validity );
}
