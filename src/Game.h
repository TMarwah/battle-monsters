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
    // CONSTRUCTOR & DESTRUCTOR
    Game();
    ~Game();

    // MUTATORS
    void Init();
    void Update();
    void GetInput();
    void Draw();

    // ACCESSORS
    Player* getPlayers() const;


    // OPERATOR OVERLOADS


};


#endif // GAME_H