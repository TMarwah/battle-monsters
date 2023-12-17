#include "abstract/MoveSet.h"

class SpecialAttack : public MoveSet {
    private:
        unsigned _effective_turn;
    
    public:
        SpecialAttack(const std::string& moveName, float accuracy=0, int damage=0, int priority=0);
        virtual int skillMethod(MonsterType baseAttackType=NORMAL, int basePower=0, MonsterType baseDefenseType, int baseDefense=0);
        
}