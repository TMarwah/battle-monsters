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
    ASSERT_NO_THROW(Monster* monster = new Monster("Andrewsaurus"));
}

TEST(MonsterTestSuite, ConstructorNameSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_EQ(monster->getName(), "Andrewsaurus");
}

TEST(MonsterTestSuite, ConstructorTypeSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_EQ(monster->getType(), NORMAL);
}

TEST(MonsterTestSuite, ConstructorBasePowerSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_NEAR(monster->getPower(), 0.0, 0.001);
}

TEST(MonsterTestSuite, ConstructorBaseDefenseSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_NEAR(monster->getDefense(), 0.0, 0.001);
}

TEST(MonsterTestSuite, AttackTest) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    // FIXME: attackDamage should be arbitrary later when attack method is implemented
    int attackDamage = 10;
    EXPECT_EQ(monster->attack(), attackDamage);
}

TEST(MonsterTestSuite, DefenseTest) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    // this should be the amount that return true since the health is 100 and attack damage is < 100
    EXPECT_TRUE(monster->defend(99));
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
}

// Things to write Unit Test About

/*
//member function for use when attacking a monster
int Move(Monster* defendingMonster, string _type, int _basePower);

// GETTERS
// member function to call the list of moves
HealthBar& getHealthBar();
int getHealthPoint();

// SETTERS
void setPower(int power);
void setDefense(int defense);
void setType(Type type);
    // will be implemented...

//setup monster moveset by creating moveset vector
*/


/*
void Monster::operator= (const Monster& target) :
    _name(target._name),
    _type(target._type),
    _basePower(target._basePower),
    _baseDefense(target._baseDefense)
{ }

void Monster::operator= (Monster* target) :
    _name(target->_name),
    _type(target->_type),
    _basePower(target->_basePower),
    _baseDefense(target->_baseDefense)
{ }
*/

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