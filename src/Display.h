#pragma once
#include <iostream>
#include "State.h"
#include "Timer.h"
#include "GameComponents.h"
#include "./interface/ColorInterface.h"


class Display : public State, public ColorInterface
{
    
private:
    Timer _timer;

public:
    // ACCESSORS
    void render(GameComponents& gameComponents);

private:
    // PRIVATE HELPERS
    void renderStartup();
    void renderPlayersSetup() const;
    void renderDraft(const std::string& p1_name,
                     const std::string& p2_name,
                     DraftBoard* draftBoard);
    void renderBattle(const std::string& p1_name,
                     const std::string& p2_name,
                     const Bench* p1_bench,
                     const Bench* p2_bench) const;
    void renderBattleOver(GameComponents& gameComponents);
    void renderPlayAgain() const;
    void renderQuit();

    
};
