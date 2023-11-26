#pragma once
#include "State.h"
#include "abstract/EventHandler.h"
#include "enum/GameState.h"
#include "enum/EventType.h"
#include "Input.h"
#include "GameComponents.h"
#include "Display.h"
#include "Event.h"
#include "Player.h"
#include "Timer.h"
#include "Helper.h"


class Game: public State,   // a public inheritance of State class
            public EventHandler
{

private:
    bool _isRunning;
    Input _input;
    GameComponents _gameComponents;
    Display _display;
    // Timer _timer;
    


public:
    // MUTATORS
    void init();
    void getInput();
    void handleEvents();

    // ACCESSORS
    void render();
    bool isRunning() const;

    // VIRTUAL OVERRIDES
    void addEventHandler(const Event& event);

private:
    // PRIVATE HELPERS
    void setGameState(GameState state);
    void quit();
    void handleStartUp();
    void handlePlayersSetup(const Event& event);
    void handleDraft(const Event& event);
    void handleBattle(const Event& event);
    void handleBattleOver();
    void handlePlayAgain(const Event& event);
    void handleQuit();

};