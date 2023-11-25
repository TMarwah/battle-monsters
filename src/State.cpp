#include "State.h"


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
State::State() : _state{NULL_ST} {}

/*******************************************************************************
* MUTATORS
*******************************************************************************/
void State::setState(GameState state) {
    _state = state;
}

/*******************************************************************************
* ACCESSORS
*******************************************************************************/
GameState State::getState() const {
    return _state;
}