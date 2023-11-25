#pragma once
#include "enum/GameState.h"


class State {

private:
    GameState _state;

public:
    // CONSTRUCTOR
    State();
    
    // MUTATORS
    void setState(GameState state);

    // ACCESSORS
    GameState getState() const;

};