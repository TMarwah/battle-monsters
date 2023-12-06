#pragma once
#include "enum/MonsterType.h"
#include "./abstract/MoveSet.h"
#include "NormalAttack.h"
#include <vector>


class Skillset
{
private:
    MonsterType _type;
    int _basePower;
    int _baseDefense;
    std::vector<MoveSet *> _moveset;
    unsigned _moveIndex;

public:
    // CONSTRUCTOR
    Skillset(MonsterType type=NORMAL, int basePower=0, int baseDefense=0);
    // Copy Constructor
    Skillset(const Skillset& target);

    // SETTERS
    void setType(MonsterType type);
    void setPower(int power);
    void setDefense(int defense);
    void addMoves(const std::vector<MoveSet *>& newMoves);
    void setMoveIndex(unsigned index);

    // GETTERS
    MonsterType getType() const;
    int getPower() const;
    int getDefense() const;
    const std::vector<MoveSet *>& getMoves() const;
    unsigned getMoveIdex() const;
    MoveSet* getMove() const;

    // OPERATOR OVERLOADS
    void operator= (const Skillset& rhs); 

};

