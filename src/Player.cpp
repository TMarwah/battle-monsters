#include <Player.h>

//Constructor
Player::Player(){
    //init empty bench and no name
    //_bench = nullptr;
    _name = "";
}

std::string Player::getName(){
    return _name;
}

//TODO implement bench class
/*
Player::getBench(){
    //TODO complete bench code
    return _bench;
}

*/