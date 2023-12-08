#include "gtest/gtest.h"
#include "../src/Skillset.h"
#include "../src/enum/MonsterType.h"


TEST(SkillsetTestSuite, DefaultConstructorTest) {
    
    // ARRANGE
    Skillset skillset;

    // ACT

    // ASSERT
    EXPECT_EQ(skillset.getType(), MonsterType::NORMAL);
    EXPECT_EQ(skillset.getPower(), 0);
    EXPECT_EQ(skillset.getDefense(), 0);

}

TEST(SkillsetTestSuite, SettersTest) {
    
    // ARRANGE
    Skillset skillset;

    // ACT
    skillset.setType(NULL_TYPE);
    skillset.setPower(66);
    skillset.setDefense(88);
    skillset.setMoveIndex(2);

    // ASSERT
    EXPECT_EQ(skillset.getType(), MonsterType::NULL_TYPE);
    EXPECT_EQ(skillset.getPower(), 66);
    EXPECT_EQ(skillset.getDefense(), 88);
    EXPECT_EQ(skillset.getMoveIdex(), 2);
    
}

TEST(SkillsetTestSuite, GetMoveTest) {
    
    // ARRANGE
    Skillset skillset;

    // ACT
    skillset.addMove(new NormalAttack("move1", 0, 0, 0));
    skillset.setMoveIndex(0);

    // ASSERT
    EXPECT_EQ(skillset.getMove()->getName(), "move1");
    
    delete skillset.getMove();
}
