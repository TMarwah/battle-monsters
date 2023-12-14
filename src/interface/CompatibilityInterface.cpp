#include "CompatibilityInterface.h"


// Type Compatibility
/*
 * EFFECTIVE: 1.25 attack / 0.75 defense
 * NOT EFFECTIVE: 0.75 attack / 1.25 defense
 - NORMAL = * All Types ( 1.1 attack / 1.0 defense )
 - FIRE > AIR ( EFFECTIVE ); FIRE < WATER ( NOT EFFECTIVE )
 - WATER > FIRE ( EFFECTIVE ); WATER < EARTH ( NOT EFFECTIVE )
 - EARTH > WATER ( EFFECTIVE ); EARTH < AIR ( NOT EFFECTIVE )
 - AIR > EARTH ( EFFECTIVE ); AIR < FIRE ( NOT EFFECTIVE )
*/

float CompatibilityInterface::getCompatibility(MonsterType attackType, MonsterType defenseType) const {
    float compatibilityRatio = 0.0;

    // if attacker is NORMAL
    if(attackType == MonsterType::NORMAL) {
        compatibilityRatio = 1.1;
    }

    // if attacker is FIRE
    else if(attackType == MonsterType::FIRE) {
        switch (defenseType)
        {
        case MonsterType::AIR:
            compatibilityRatio = 1.25; 
            break;

        case MonsterType::WATER:
            compatibilityRatio = 0.75; 
            break;
        
        default:
            compatibilityRatio = 1.0;
            break;
        }
    }

    // if attacker is WATER
    else if(attackType == MonsterType::WATER) {
        switch (defenseType)
        {
        case MonsterType::FIRE:
            compatibilityRatio = 1.25; 
            break;

        case MonsterType::EARTH:
            compatibilityRatio = 0.75; 
            break;
        
        default:
            compatibilityRatio = 1.0;
            break;
        }
    }

    // if attacker is EARTH
    else if(attackType == MonsterType::EARTH) {
        switch (defenseType)
        {
        case MonsterType::WATER:
            compatibilityRatio = 1.25; 
            break;

        case MonsterType::AIR:
            compatibilityRatio = 0.75; 
            break;
        
        default:
            compatibilityRatio = 1.0;
            break;
        }
    }

    // if attacker is AIR
    else if(attackType == MonsterType::AIR) {
        switch (defenseType)
        {
        case MonsterType::EARTH:
            compatibilityRatio = 1.25; 
            break;

        case MonsterType::FIRE:
            compatibilityRatio = 0.75; 
            break;
        
        default:
            compatibilityRatio = 1.0;
            break;
        }
    }

    // if error
    else {
        compatibilityRatio = 0;
    }

    return compatibilityRatio;
}

// float CompatibilityInterface::getCompatibility(Monster& attackMonster, Monster& defenseMonster) const {
//     return getCompatibility(attackMonster.getType(), defenseMonster.getType());
// }