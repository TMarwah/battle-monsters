#pragma once
#include <iostream>
#include "enum/GameState.h"
#include "Event.h"


class Helper {
public:
    static void logState(std::string objectName,
                         GameState state);

    static void logEvent(Event event,
                         std::string callLocation);
                         

};