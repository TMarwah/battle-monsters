#pragma once
#include "./abstract/MoveSet.h"
#include <string>

class NormalAttack : public MoveSet 
{
    public:
        NormalAttack(const std::string& moveName, float accuracy=0, int damage=0, int priority=0);
        virtual int skillMethod(MonsterType baseAttackType=NORMAL, int basePower=0, MonsterType baseDefenseType=NORMAL, int baseDefense=0);

        virtual MoveSet* clone() const;
};