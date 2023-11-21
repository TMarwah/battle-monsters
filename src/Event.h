#pragma once
#include "enum/EventType.h"

struct Event
{
    EventType eventType {EventType::NULL_EVENT};
    std::string data = "null";
    std::string data2 = "null";

};
