#include <gtest/gtest.h>
#include "../src/Monster.h"


TEST(Monster2TestSuite, ConstructorNoThrow) {
    // ARRANGE & ACT & ASSERT
    Monster* monster;
    ASSERT_NO_THROW(monster = new Monster("Andrewsaurus"));

    delete monster;
}

TEST(Monster2TestSuite, ConstructorNameSetup) {
    // ARRANGE
    Monster* monster = new Monster("Andrewsaurus");

    // ACT & ASSERT
    EXPECT_EQ(monster->getName(), "Andrewsaurus");

    delete monster;
}

