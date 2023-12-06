#include "gtest/gtest.h"
#include "../src/Skillset.h"
#include "../src/enum/MonsterType.h"


TEST(SkillsetTest, Defaults) {
    
    // ARRANGE
    Skillset skillset;

    // ACT

    // ASSERT
    EXPECT_EQ(skillset.getType(), MonsterType::NORMAL);
    EXPECT_EQ(skillset.getPower(), 0);
    EXPECT_EQ(skillset.getDefense(), 0);

}

TEST(SkillsetTest, Setters) {
    
    // ARRANGE
    Skillset skillset;

    // ACT
    skillset.setType(NULL_TYPE);
    skillset.setPower(66);
    skillset.setDefense(88);

    // ASSERT
    EXPECT_EQ(skillset.getType(), MonsterType::NULL_TYPE);
    EXPECT_EQ(skillset.getPower(), 66);
    EXPECT_EQ(skillset.getDefense(), 88);
    
}