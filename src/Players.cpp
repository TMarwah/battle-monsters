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

/*******************************************************************************
* ACCESSORS
*******************************************************************************/
const Player& Players::getPlayer(unsigned index) const {
    assert(index < NUM_OF_PLAYERS);

    return _players[index];

}
