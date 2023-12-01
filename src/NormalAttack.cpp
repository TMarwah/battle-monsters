#include "NormalAttack.h"
#include <math>
#include <time>

void SkillMethod(MonsterType baseType, int baseAttack, int baseOpponentDefense) {
    // get random 0-99 value
    srand(time(0)); 
    int randomAccuracy = (rand() % 100) + 1;
    
    // if normal attack hits
    if(0.01*randomAccuracy <= _defaultAccuracy) {
        float damage = ( 0.5 * baseAttack ) + _defaultDamage - ( 0.3 * baseDefense );
    }
}