#pragma once
#include "State.h"
#include "Player.h"
#include "definitions/Definitions.h"


class Players : public State
{
    Player* _players;

public:
    // CONSTRUCTOR & DESTRUCTOR
    Players();
    ~Players();

    // MUTATORS
    void setNames(const Event& event);

    // ACCESSORS
    const Player& getPlayer(unsigned index) const;

};