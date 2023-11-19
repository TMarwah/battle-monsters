#pragma once
#include <string>
//TODO import bench once complete
class Player{
    protected:
    //Bench _bench;
    std::string _name;

    public:
    Player(); //player constructor

    std::string getName(); //return player name

    //getBench(); //TODO implement bench

};