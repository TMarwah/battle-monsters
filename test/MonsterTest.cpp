#include <gtest/gtest.h>
#include "../src/Monster.h"

#include "../src/abstract/MoveSet.h"
#include "../src/NormalAttack.h"
#include <vector>

/*
Monster(MonsterType _type, int _basePower=0, int _baseDefense=0);
~Monster();
*/

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

TEST(MonsterTestSuite, ConstructorTypeSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_EQ(monster->getType(), NORMAL);

    delete monster;
}

TEST(MonsterTestSuite, ConstructorBasePowerSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_NEAR(monster->getPower(), 0.0, 0.001);

    delete monster;
}

TEST(MonsterTestSuite, ConstructorBaseDefenseSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_NEAR(monster->getDefense(), 0.0, 0.001);

    delete monster;
}

TEST(MonsterTestSuite, AttackTest) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    // FIXME: attackDamage should be arbitrary later when attack method is implemented
    int attackDamage = 10;
    EXPECT_EQ(monster->attack(), attackDamage);

    delete monster;
}

TEST(MonsterTestSuite, DefenseTest) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    // this should be the amount that return true since the health is 100 and attack damage is < 100
    EXPECT_TRUE(monster->defend(99));

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

    delete monster;
}

/*
TEST(MonsterTestSuite, AttackFunctionTest) {
    // ARRANGE
    Monster* monsterA = new Monster("MonsterA");
    std::vector<MoveSet *> MonsterA_MoveSet;
    Monster* monsterB= new Monster("MonsterB");
    std::vector<MoveSet *> MonsterB_MoveSet;

    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    MonsterA_MoveSet.push_back(new NormalAttack("Tackle", 0.9, 25, 1));
    MonsterB_MoveSet.push_back(new NormalAttack("Headbutt", 0.9, 25, 1));

    //establish corresponding monster movesets
    monsterA->addMoves(MonsterA_MoveSet);
    monsterB->addMoves(MonsterB_MoveSet);

    //setup specific move pointers
    MoveSet* Tackle = monsterA->getMoves().at(0);
    MoveSet* Headbutt = monsterB->getMoves().at(0);

    // ACT & ASSERT
    // this should be the amount that return true since the health is 100 and attack damage is < 100
    EXPECT_TRUE(monster->defend(99));

    delete monster;
}
*/


TEST(MonsterTestSuite, HealthBarGetterTest) {
    // ARRANGE
    Monster* monsterA = new Monster("MonsterA");
    HealthBar* monsterA_HealthBar = new HealthBar();

    Monster* monsterB = new Monster("MonsterB");
    HealthBar* monsterB_HealthBar = new HealthBar();

    // ACT
    monsterA_HealthBar->deductHP(25);
    monsterB_HealthBar->deductHP(50);

    // ASSERT
    EXPECT_EQ(monsterA_HealthBar->getHP(), 75);
    EXPECT_EQ(monsterB_HealthBar->getHP(), 50);

    delete monsterA;
    delete monsterA_HealthBar;
    delete monsterB;
    delete monsterB_HealthBar;
}

TEST(MonsterTestSuite, StatSetterTest) {
    // ARRANGE
    Monster* monster = new Monster("Tanmaysaurus");

   // ACT
    monster->setPower(55);
    monster->setDefense(10);
    monster->setType(NORMAL);

   // ASSERT
    EXPECT_EQ(monster->getPower(), 55);
    EXPECT_EQ(monster->getDefense(), 10);
    EXPECT_EQ(monster->getType(), NORMAL);

    delete monster;
    
}

// Overloaded Operators & Constructor
TEST(MonsterTestSuite, CopyConstructor) {
    // ARRANGE
    Monster monster1 = Monster("Andrewsaurus", NORMAL, 1, 1);

    // ACT
    Monster monster2 = monster1;

    // ASSERT
    EXPECT_EQ(monster1.getName(), monster2.getName());
    EXPECT_EQ(monster1.getPower(), monster2.getPower());
    EXPECT_EQ(monster1.getDefense(), monster2.getDefense());
}

TEST(MonsterTestSuite, AssignmentOperatorOverload_ByReference) {
    // ARRANGE
    Monster monster1 = Monster("Andrewsaurus", NORMAL, 1, 1);
    Monster monster2 = Monster("Willzilla", NORMAL, 0, 0);

    // QUICK CHECK
    EXPECT_NE(monster1.getName(), monster2.getName());
    EXPECT_NE(monster1.getPower(), monster2.getPower());
    EXPECT_NE(monster1.getDefense(), monster2.getDefense());

    // ACT
    monster1 = monster2;

    // ASSERT
    EXPECT_EQ(monster1.getName(), monster2.getName());
    EXPECT_EQ(monster1.getPower(), monster2.getPower());
    EXPECT_EQ(monster1.getDefense(), monster2.getDefense());
}