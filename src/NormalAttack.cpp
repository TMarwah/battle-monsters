#include "NormalAttack.h"
#include <cmath>
#include <ctime>


NormalAttack::NormalAttack(const std::string& name, float accuracy, int damage, int priority) :
    MoveSet(name, accuracy, damage, priority)
{}

int NormalAttack::skillMethod(MonsterType baseType, int basePower, int baseOpponentDefense) {
    // get random 0-99 value
    srand(time(0)); 
    int randomAccuracy = (rand() % 100) + 1;
    
    // if normal attack hits
    int damage = 0;
    if(0.01*randomAccuracy <= getAccuracy()) {
        damage = ( 0.5 * basePower ) + getDamage() - ( 0.75 * baseOpponentDefense );
    }   
    else {
        // attack is missed
        setState(GameState::ATTACK_MISSED_ST);
    }

    return damage;
}

MoveSet* NormalAttack::clone() const {
    return new NormalAttack(*this);
}