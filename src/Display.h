#pragma once
#include <iostream>
#include "State.h"
#include "GameComponents.h"
#include "Timer.h"


class Display : public State
{
    
private:
    Timer _timer;

public:
    // ACCESSORS
    void render(const GameComponents& gameComponents);

private:
    // PRIVATE HELPERS
    void renderStartup();
    void renderPlayersSetup() const;
    void renderDraft(const std::string& p1_name,
                     const std::string& p2_name) const;
    void renderBattle() const;
    void renderBattleOver();
    void renderPlayAgain() const;
    void renderQuit();

};