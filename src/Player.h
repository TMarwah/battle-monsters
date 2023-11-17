#pragma once
#include <string>
//TODO import bench once complete
class Player{
    protected:
    //Bench _bench;
    std::string _name;

    public:
    Player(); //player constructor

    std::string GetName(); //return player name

    //GetBench(); //TODO implement bench

};