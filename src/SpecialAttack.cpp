#include "abstract/MoveSet.h"
#include "SpecialAttack.h"
#include <cmath>
#include <ctime>

SpecialAttack::SpecialAttack(const std::string& moveName, float accuracy, int damage, int priority) :
    MoveSet(name, accuracy, damage, priority)
{ }


virtual int SpecialAttack::skillMethod(MonsterType baseAttackType, int basePower, MonsterType baseDefenseType, int baseDefense) {
    // get random 0-99 value
    srand(time(0)); 
    int randomAccuracy = (rand() % 100) + 1;
    
    // if normal attack hits
    int damage = 0;
    if(0.01*randomAccuracy <= getAccuracy()) {
        damage = ( 0.5 * basePower ) + getDamage() - ( 0.75 * baseDefense );
        // add compatibility calculation
        damage = damage * getCompatibility(baseAttackType, baseDefenseType);
    }   
    else {
        // attack is missed
        setState(GameState::ATTACK_MISSED_ST);
    }

    // check if damage is negative (it will heal if returned negative) and set it to zero
    if(damage < 0) {
        damage = 0;
    }

    return damage;
}
