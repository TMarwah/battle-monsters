#pragma once
#include "States.h"
#include "Player.h"
#include "enum/ObjectStates.h"


class Game: public States   // a public inheritance of State class
{

private:
    Player* _players;


public:
    // CONSTRUCTOR & DESTRUCTOR
    Game();
    ~Game();

    // MUTATORS
    void init();
    void update();
    void getInput();
    void draw();

    // ACCESSORS
    Player* getPlayers() const;


    // OPERATOR OVERLOADS


};