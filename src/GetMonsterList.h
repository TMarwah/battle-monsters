#pragma once

#ifndef MONSTER_IMPLEMENTED
    #include "Monster.h"
#endif

#include "./abstract/MoveSet.h"
#include "NormalAttack.h"
#include <vector>

std::vector<Monster *> getMonsterList() {
    std::vector monsterList<Monster *>;

    // 120 as a balance factor of stats = attack + defense

    Monster* Andrewsaurus = new Monster(NORMAL, 50, 70);
    std::vector AndrewsaurusMoveset<MoveSet *>;
    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    AndrewsaurusMoveset.push_back(new NormalAttack("Rock-bottom", 0.9, 25, 1));
    AndrewsaurusMoveset.push_back(new NormalAttack("Charge", 0.4, 50, 0));
    Andrewsaurus->addMoves(AndrewsaurusMoveset);
    monsterList.push_back(Andrewsaurus);

    Monster* Willzilla = new Monster(NORMAL, 60, 60);
    WillzillaMoveSet.push_back(new NormalAttack("Lazer Breath", 0.7, 35, 0));
    Willzilla->addMoves(WillzillaMoveSet);
    monsterList.push_back(Willzilla);

    return monsterList;
}