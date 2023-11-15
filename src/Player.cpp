#include <Player.h>

//Constructor
Player::Player(){
    //init empty bench and no name
    //_bench = nullptr;
    _name = "";
}

std::string Player::GetName(){
    return _name;
}

//TODO implement bench class
/*
Player::GetBench(){
    //TODO complete bench code
    return _bench;
}

*/