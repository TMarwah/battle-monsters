#include <Player.h>

//Constructor
Player::Player(){
    //init empty bench and no name
    //_bench = nullptr;
    _name = "";
}

std::string Player::getName() const {
    return _name;
}

void Player::setName(std::string name) {
    _name = name;
}

//TODO implement bench class
/*
Player::getBench(){
    //TODO complete bench code
    return _bench;
}

*/

// VIRTUAL OVERRIDES
void Player::addEventHandler(Event event) {
    if(event.eventType == EventType::SET_NAMES) {
        setName(event.data); 
    }

}

void Player::update() {

}