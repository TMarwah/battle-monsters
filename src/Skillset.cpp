#include "Skillset.h"
#include <cassert>


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
Skillset::Skillset(MonsterType type, int basePower, int baseDefense) :
    _type(type),
    _basePower(basePower),
    _baseDefense(baseDefense)
{ }

// Skillset::Skillset(const Skillset& target) :
//     _type(target._type),
//     _basePower(target._basePower),
//     _baseDefense(target._baseDefense)
// {
//     for(unsigned int i = 0; i < target._moveset.size(); ++i) {
//         MoveSet* copyMove = target._moveset.at(i)->clone();
//         _moveset.push_back(copyMove);
//     }
// }

Skillset::~Skillset() {
    // for(unsigned int i = 0; i < _moveset.size(); ++i){
    //     if(_moveset.at(i) != nullptr) {
    //         delete _moveset.at(i);
    //     }
    // }
}

/*******************************************************************************
* SETTERS
*******************************************************************************/
void Skillset::setType(MonsterType type) {
    _type = type;

}

void Skillset::setPower(int power) {
    _basePower = power;

}

void Skillset::setDefense(int defense) {
    _baseDefense = defense;

}

void Skillset::setMoveIndex(unsigned index) {
    _moveIndex = index;
}

void Skillset::addMove(MoveSet* newMove) {
    assert(newMove != nullptr);
    _moveset.push_back(newMove);
}

void Skillset::addMoves(const std::vector<MoveSet *>& newMoves) {
    for(unsigned i = 0; i < _moveset.size(); ++i) {
        if(_moveset.at(i) != nullptr) {
            delete _moveset.at(i);
        }
    }

    _moveset = newMoves;
}


/*******************************************************************************
* GETTERS
*******************************************************************************/
MonsterType Skillset::getType() const {
    return _type;

}

int Skillset::getPower() const {
    return _basePower;

}

int Skillset::getDefense() const {
    return _baseDefense;
}

const std::vector<MoveSet *>& Skillset::getMoves() const {
    return _moveset;
}

unsigned Skillset::getMoveIdex() const {
    return _moveIndex;
}

MoveSet* Skillset::getMove() const {
    return _moveset.at(_moveIndex);
}


/*******************************************************************************
* OVERLOADED OPERATORS
*******************************************************************************/
// void Skillset::operator=(const Skillset& rhs) {
//     _type = rhs._type;
//     _basePower = rhs._basePower;
//     _baseDefense = rhs._baseDefense;
//     // TODO: add moveset copy

//     for(unsigned int i = 0; i < _moveset.size(); ++i) {
//         if(_moveset.at(i) != nullptr) {
//             delete _moveset.at(i);
//         }
//     }

//     for(unsigned int i = 0; i < rhs._moveset.size(); ++i) {
//         MoveSet* copyMove = rhs._moveset.at(i)->clone();
//         _moveset.push_back(copyMove);
//     }

// }