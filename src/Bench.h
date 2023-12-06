#pragma once
#include "Monster.h"
#include "definitions/Definitions.h"
#include <iostream>

class Bench {
private:
    Monster* _bench;    // Monster array
    int _draftCount;

public:
    // CONSTRUCTOR & DESTRUCTOR
    Bench();
    ~Bench();

    // MUTATORS
    void addMonster(const Monster& monster);
    // void setCurrent(unsigned index);
    void reset();

    // ACCESSORS
    Monster& getCurrent();
    Monster& getCurrent() const;
    unsigned getDraftCount() const;

};