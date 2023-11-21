#pragma once
#include "enum/GameEvent.h"
#include <iostream>


class Event {
private:
    GameEvent _event;

public:
    Event();

    // MUTATORS
    void setEvent(GameEvent gameEvent);

    // ACCESSORS
    void logEvent(std::string callLocation) const;
    GameEvent getEvent() const;

};

