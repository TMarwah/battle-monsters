#pragma once
#include <vector>
#include <iostream>
#include <cassert>
#include "definitions/Definitions.h"
#include "enum/GameState.h"
#include "Monster.h"
#include "NormalAttack.h"
#include "State.h"


class DraftBoard : public State {
private:
    Monster* _draftBoard;
    // std::vector<std::string> _draftBoard;

public:
    DraftBoard();
    ~DraftBoard();

    // MUTATORS
    // void reset();
    // Monster* pick(unsigned index);

    // ACCESSORS
    Monster at(unsigned index);
    Monster at(unsigned index) const;
    // std::string at(unsigned index);
    // std::string at(unsigned index) const;
    unsigned size() const;

};