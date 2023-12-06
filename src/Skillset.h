#pragma once
#include "enum/MonsterType.h"


class Skillset
{
private:
    MonsterType _type;
    int _basePower;
    int _baseDefense;
    // TODO: std::vector<MoveSet *> _moveset;

public:
    // CONSTRUCTOR
    Skillset(MonsterType type=NORMAL, int basePower=0, int baseDefense=0);

    // SETTERS
    void setType(MonsterType type);
    void setPower(int power);
    void setDefense(int defense);

    // GETTERS
    MonsterType getType() const;
    int getPower() const;
    int getDefense() const;

    // OPERATOR OVERLOADS
    void operator= (const Skillset& rhs); 

};

