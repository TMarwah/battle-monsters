#pragma once
#include "./abstract/MoveSet.h"
#include <string>

class NormalAttack : public MoveSet 
{
    public:
        NormalAttack(const std::string& moveName, float accuracy=0, int damage=0, int priority=0);
        virtual int skillMethod(MonsterType baseType, int basePower, int baseOpponentDefense);

        virtual MoveSet* clone() const;
};