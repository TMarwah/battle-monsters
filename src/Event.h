#pragma once
#include "enum/EventType.h"

struct Event
{
    EventType eventType {EventType::NULL_EVENT};
    const char* data1 = "null";
    const char* data2 = "null";

};
