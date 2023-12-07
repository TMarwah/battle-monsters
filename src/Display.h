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

    // FORMATTING HELPRS
    std::string red(const std::string& ) const;
    std::string red(int message) const;
    std::string red(float message) const;
    std::string red_underline(const std::string& ) const;

    std::string white(const std::string& ) const;
    std::string cyan(const std::string& ) const;
    std::string blue(const std::string& ) const;
    std::string magenta(const std::string& ) const;
    std::string green(int ) const;
};
