#include <gtest/gtest.h>
#include "../src/Monster.h"
#include "../src/abstract/MoveSet.h"
#include "../src/NormalAttack.h"


TEST(MonsterTestSuite, ConstructorNoThrow) {
    // ARRANGE & ACT & ASSERT
    Monster* monster;
    ASSERT_NO_THROW(monster = new Monster("Andrewsaurus"));

    delete monster;
}

TEST(MonsterTestSuite, ConstructorNameSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_EQ(monster->getName(), "Andrewsaurus");

    delete monster;
}

TEST(MonsterTestSuite, AddingMovesNoThrow) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");
    std::vector<MoveSet *> AndrewsaurusMoveset;
    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    AndrewsaurusMoveset.push_back(new NormalAttack("Rock-bottom", 0.9, 25, 1));
    AndrewsaurusMoveset.push_back(new NormalAttack("Charge", 0.4, 50, 0));

    // ACT
    EXPECT_NO_THROW(monster->addMoves(AndrewsaurusMoveset));

    for(unsigned i = 0; i < monster->getMoves().size(); ++i) {
        if(monster->getMoves().at(i) != nullptr) {
            delete monster->getMoves().at(i);
        }
    }

    delete monster;
}

TEST(MonsterTestSuite, AddingMovesTest) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");
    std::vector<MoveSet *> AndrewsaurusMoveset;
    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    AndrewsaurusMoveset.push_back(new NormalAttack("Rock-bottom", 0.9, 25, 1));
    AndrewsaurusMoveset.push_back(new NormalAttack("Charge", 0.4, 50, 0));

    // ACT
    monster->addMoves(AndrewsaurusMoveset);
    MoveSet* rockBottom = monster->getMoves().at(0);
    MoveSet* charge = monster->getMoves().at(1);

    // ASSERT
    // 1. check if pointers are set to null
    ASSERT_TRUE(rockBottom);
    ASSERT_TRUE(charge);

    // 2. check if moves are in the correct order
    EXPECT_EQ(rockBottom->getName(), "Rock-bottom");
    EXPECT_EQ(charge->getName(), "Charge");

    delete rockBottom;
    delete charge;
    delete monster;
}

TEST(MonsterTestSuite, HealthBarGetterTest) {
    // ARRANGE
    Monster* monsterA = new Monster("MonsterA");
    Monster* monsterB = new Monster("MonsterB");

    // ACT
    monsterA->deductHP(25);
    monsterB->deductHP(50);

    // ASSERT
    EXPECT_EQ(monsterA->getHP(), 75);
    EXPECT_EQ(monsterB->getHP(), 50);

    delete monsterA;
    delete monsterB;
}