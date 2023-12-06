#include <Player.h>


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
Player::Player(){
    //init empty bench and no name
    //_bench = nullptr;
    _name = "";
}


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Player::setName(std::string name) {
    _name = name;
}

void Player::reset() {
    _bench.reset();
}

void Player::draft(const Monster& monster) {
    _bench.addMonster(monster);

}

//TODO implement bench class
/*
Player::getBench(){
    //TODO complete bench code
    return _bench;
}
*/


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
std::string Player::getName() const {
    return _name;
}

const Bench* Player::getBench() const {
    return &_bench;
}


/*******************************************************************************
* VIRTUAL OVERRIDES
*******************************************************************************/
void Player::addEventHandler(const Event& event) {

}
