#pragma once
#include "enum/ObjectStates.h"
#include "States.h"
#include "Event.h"
#include "Player.h"
#include "Input.h"
#include "Display.h"
#include "Timer.h"


class Game: public States   // a public inheritance of State class
{

private:
    Player* _players;
    Input _input;
    Display _display;
    Timer _timer;
    


public:
    // CONSTRUCTOR & DESTRUCTOR
    Game();
    ~Game();

    // MUTATORS
    void init();
    void getInput();
    // void draw();
    void handleEvents();

    // ACCESSORS
    void render() const;
    Player* getPlayers() const;
    bool isRunning() const;

    // OPERATOR OVERLOADS

    // VIRTUAL OVERRIDES
    void addEventHandler(Event event);
    void update();

};