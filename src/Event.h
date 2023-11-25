#pragma once
#include <string>
#include "enum/EventType.h"

struct Event
{
    EventType eventType {EventType::NULL_EVENT};
    std::string data1 = "null";
    std::string data2 = "null";

};
