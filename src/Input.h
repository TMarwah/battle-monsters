#pragma once
#include <iostream>
#include <cstring>
#include "State.h"
#include "GameComponents.h"
#include "Event.h"


class Input : public State
{

private:
    // MEMBERS
    Event _event;

public:
    // MUTATORS
    void getInput(const GameComponents& gameComponents);

    // ACCESSORS
    Event getEvent() const;

private:
    // PRIVATE HELPERS
    void getPlayersSetupInput();
    void getDraftInput();
    void getBattleInput(const GameComponents& gameComponents);
    void getPlayAgainInput();

    // VALIDATORS
    bool isValidDraftInput(const std::string& input1, const std::string& input2) const;
    bool isValidBattleInput(const std::string& input1, const std::string& input2) const;

};