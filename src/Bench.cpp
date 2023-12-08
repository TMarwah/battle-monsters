#include "Bench.h"
#include "definitions/Definitions.h"
#include <cassert>


/*******************************************************************************
* CONSTRUCTOR & DESTRUCTOR
*******************************************************************************/
Bench::Bench() {
    if(FLAG_ON) {
        std::cout << "Bench::Bench" << '\n';
    }

    // allocate for Monster*
    _bench = new Monster[BENCH_SIZE];

    // set Monster count to 0 because no Monsters on the bench yet
    _draftCount = 0;

}

Bench::~Bench() {
    delete[] _bench;
}


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Bench::addMonster(const Monster& monster) {
    
    // std::cout << "Bench::addMonster" << '\n';

    // // assert bench is not full
    assert(_draftCount < BENCH_SIZE);

    _bench[_draftCount] = monster;

    _draftCount++;

}

void Bench::reset() {
    _draftCount = 0;
}

/*******************************************************************************
* ACCESSORS
*******************************************************************************/
Monster& Bench::getCurrent() {
    
    return _bench[0];
    
}

Monster& Bench::getCurrent() const {
    
    return _bench[0];
    
}

unsigned Bench::getDraftCount() const {
    return _draftCount;
}