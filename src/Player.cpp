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
    setState(DRAFT_ST);
    _bench.reset();
}

void Player::draft(const Monster& monster) {
    _bench.addMonster(monster);

}

void Player::setNextMove(const std::string& moveIndex) {

    if(moveIndex == "1") {
        _bench.getCurrent().getSkillset().setMoveIndex(0);
    }
    else if(moveIndex == "2") {
        _bench.getCurrent().getSkillset().setMoveIndex(1);
    }
    else if(moveIndex == "3") {
        _bench.getCurrent().getSkillset().setMoveIndex(2);
    }
    else if(moveIndex == "4") {
        _bench.getCurrent().getSkillset().setMoveIndex(3);
    }
    else {
        assert(true);
    }
}

void Player::update() {
    if(getBench()->getCurrent().isDead()) {
        setState(DEFEATED_ST);
    }
}

bool Player::isDefeated() const {
    if(FLAG_ON) {
        std::cout << "isDefeated" << (getState() == GameState::DEFEATED_ST) << "\n";
    }
    
    return getState() == GameState::DEFEATED_ST;
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
// void Player::addEventHandler(const Event& event) {

//     switch(getState())
//     {

//         case BATTLE_ST:
//             handleBattle(event);
//             break;

//     }

// }

// void Player::handleBattle(const Event&) {

// }