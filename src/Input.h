#pragma once
#include <iostream>
#include "Event.h"
#include "States.h"


class Input : public States
{
private:
    // MEMBERS
    Event _event;


public:
    // MUTATORS
    // bool pollEvent(Event& gameEvent);
    void getInput();

    // ACCESSORS
    Event getEvent() const;


private:
    // PRIVATE HELPERS
    void getPlayerNamesInput();
    void getDraftInput();
    void getBattleInput();
    void getReplayInput();

};