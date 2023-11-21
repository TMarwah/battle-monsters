#pragma once


class EventHandler {
    
    virtual void addEventHandler(Event event) = 0;
    virtual void update() = 0;
    
}