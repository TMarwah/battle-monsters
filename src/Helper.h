#pragma once
#include <iostream>
#include "enum/ObjectStates.h"
#include "States.h"
#include "Event.h"


class Helper {
public:
    static void logState(States statesObject,
                         std::string objectName);

    static void logEvent(Event event,
                         std::string callLocation);
                         

};