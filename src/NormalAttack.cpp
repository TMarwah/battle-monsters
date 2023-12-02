#include "NormalAttack.h"
#include <cmath>
#include <ctime>


NormalAttack::NormalAttack(const std::string& name, float accuracy, int damage, int priority) :
    MoveSet(name, accuracy, damage, priority)
{}

void NormalAttack::SkillMethod(MonsterType baseType, int baseAttack, int baseOpponentDefense) {
    // get random 0-99 value
    srand(time(0)); 
    int randomAccuracy = (rand() % 100) + 1;
    
    // if normal attack hits
    float damage = 0;
    if(0.01*randomAccuracy <= GetAccuracy()) {
        damage = ( 0.5 * baseAttack ) + GetAccuracy() - ( 0.3 * baseOpponentDefense );
    }

    // I have made a calculation for a damage but we haven't figured out how to send this data to another Monster's Healthbar
}