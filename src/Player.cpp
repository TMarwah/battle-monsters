#include <Player.h>

//Constructor
Player::Player(){
    //init empty bench and no name
    _bench = nullptr;
    _name = "";
}

Player::GetName(){
    return _name;
}

Player::GetBench(){
    //TODO complete bench code
    return _bench;
}