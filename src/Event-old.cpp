#include "Event.h"
#include <iostream>


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
Event::Event() : _event{NULL_EVENT} {}


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Event::setEvent(GameEvent gameEvent) {
    _event = gameEvent;

}


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
void Event::logEvent(std::string callLocation) const {
    std::cout << "Event::logEvent | " << callLocation << " | GameEvent: ";
    if(getEvent() == GameEvent::SET_PLAYER_NAMES) {std::cout << "SET_PLAYER_NAMES ";}
    if(getEvent() == GameEvent::A) {std::cout << "A ";}
    if(getEvent() == GameEvent::B) {std::cout << "B ";}
    if(getEvent() == GameEvent::NULL_EVENT) {std::cout << "NULL_EVENT ";}
    std::cout << std::endl;
}

GameEvent Event::getEvent() const {
    return _event;
    
}