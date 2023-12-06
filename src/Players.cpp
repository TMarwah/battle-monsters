#include "Players.h"
#include <cassert>


/*******************************************************************************
* CONSTRUCTOR & DESTRUCTOR
*******************************************************************************/
Players::Players() {
    _players = new Player[NUM_OF_PLAYERS];

}

Players::~Players() {
    delete[] _players;
}

/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Players::setNames(const Event& event) {
    _players[0].setName(event.data1);
    _players[1].setName(event.data2);

}

void Players::fight(Monster& monster1, Monster& monster2) {

    if(FLAG_ON) {
        std::cout << "Players::fight" << "\n";
    }
    
    // TODO: implement priority feature
    // TODO: decide or randomize which player goes first 
        // attack() returns the _skillset component of Monster
    monster1.defend( monster2.attack());
    monster2.defend( monster1.attack() );

    // test if battle is over
    update();

}

/*******************************************************************************
* ACCESSORS
*******************************************************************************/
// Player& Players::getPlayer(unsigned index) const {
//     assert(index < NUM_OF_PLAYERS);

//     return _players[index];

// }

/*******************************************************************************
* VIRTUAL OVERRIDES
*******************************************************************************/
void Players::addEventHandler(const Event& event) {

    switch(getState())
    {
        case DRAFT_ST:
            handleDraft(event);
            break;

        case BATTLE_ST:
            handleBattle(event);
            break;

    }

}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
Player& Players::getPlayer(unsigned index) {
    assert(index < NUM_OF_PLAYERS);

    return _players[index];

}

// const Player& Players::getPlayer(unsigned index) const {
//     assert(index < NUM_OF_PLAYERS);

//     return _players[index];

// }

// Player& Players::getPlayer(unsigned index) const {
//     assert(index < NUM_OF_PLAYERS);

//     return _players[index];

// }

void Players::reset() {
    _players[0].reset();
    _players[1].reset();

}


void Players::update() {

    // update players
    getPlayer(0).update();
    getPlayer(1).update();

    // if either player is defeated then BATTLE_ST complete
    if(getPlayer(0).isDefeated() || getPlayer(1).isDefeated()) {
        setState(NULL_ST);
    }

}


/*******************************************************************************
* PRIVATE HELPERS - HANDLERS
*******************************************************************************/
void Players::handleDraft(const Event& event) {

}

void Players::handleBattle(const Event& event) {

    if(FLAG_ON) {
        std::cout << "Players::handleBattle" << "\n";
    }

    _players[0].setNextMove(event.data1);
    _players[1].setNextMove(event.data2);

    fight(_players[0].getBench()->getCurrent(),
          _players[1].getBench()->getCurrent());

    // if(event.eventType == EventType::ATTACK) {
    //     _players[0].getBench()->getCurrent().getSkillset().setMoveIndex(event.data1);
    //     _players[1].getBench()->getCurrent().getSkillset().setMoveIndex(event.data2);
    // }

}
