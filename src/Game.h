#ifndef GAME_H
#define GAME_H
#include "States.h"
#include "Player.h"
#include "enum/ObjectStates.h"


class Game: public States   // a public inheritance of State class
{

private:
    Player* _players;


public:
    // CONSTRUCTOR
    Game();

    // MUTATORS
    void Init();

    // ACCESSORS
    Player* getPlayers();


    // OPERATOR OVERLOADS


};


#endif // GAME_H