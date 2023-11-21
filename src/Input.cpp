#include "Input.h"




/*******************************************************************************
* MUTATORS
*******************************************************************************/
/*
bool Input::pollEvent(Event& gameEvent) {

    std::cout << "Input::pollEvent  |  peek  |  "; 
    std::cout << std::cin.peek() << std::endl;

    char byte;
    bool isInput = false;       // assume input stream empty

    // extract from stdin
    if(std::cin >> byte)
    {
        isInput = true;

        // set event based off of stdin
        if(byte == 'a')
            gameEvent.setEvent(GameEvent::A);
        else if(byte == 'b')
            gameEvent.setEvent(GameEvent::B);
        else
            gameEvent.setEvent(GameEvent::NULL_EVENT);

    }


    return isInput;
    
}
*/

void Input::getInput() {
    if(checkState(INIT)) {
        getPlayerNamesInput();
    }
    else if(checkState(DRAFT)) {
        getDraftInput();
    }
    else if(checkState(BATTLE)) {
        getBattleInput();
    }
    else if(checkState(REPLAY)) {
        getReplayInput();
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
void Input::getPlayerNamesInput() {
    
    // char name1[80] = {"name1"};
    // char name2[80] = {"name2"};
    char name1[80];
    char name2[80];
    
    std::cout << "Player 1 name: ";
    std::cin.get(name1, 80);
    std::cin.ignore(100, '\n');
    // std::cin >> name1;
    std::cout << "Player 2 name: ";
    std::cin.get(name2, 80);
    std::cin.ignore(100, '\n');
    // std::cin >> name2;

    _event.data1 = name1;
    _event.data2 = name2;
    _event.eventType = EventType::SET_NAMES;

}


void Input::getDraftInput() {

    // hold here for now
    std::cout << "getDraftInput()" << std::endl;
    std::cin.get();

}

void Input::getBattleInput() {

}

void Input::getReplayInput() {

}