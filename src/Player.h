#pragma once
#include <string>
#include "State.h"
#include "Event.h"

//TODO import bench once complete
class Player : public State {
    protected:
    //Bench _bench;
    std::string _name;

    public:


    std::string getName() const; //return player name

    //setName() method that sets player name
    void setName(std::string name); 

    //getBench(); //TODO implement bench

    // VIRTUAL OVERRIDES
    void addEventHandler(const Event& event);
    Player(); //player constructor
};