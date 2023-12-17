#pragma once
#include "../enum/MonsterType.h"
// #include "../Monster.h"

// Forward declaration of Monster to let the compiler know it will be defined later
// class Monster;

struct CompatibilityInterface {
    float getCompatibility(MonsterType attackType, MonsterType defenseType) const;
    // float getCompatibility(Monster& attackMonster, Monster& defenseMonster) const;
};