#pragma once
#include "enum/GameState.h"
#include "Event.h"


class EventHandler {
    
private:

    // PURE VIRTUAL FUNCTIONS
    virtual void addEventHandler(const Event& event) = 0;

};