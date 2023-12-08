#include "gtest/gtest.h"
#include "../src/State.h"
#include "../src/enum/GameState.h"


TEST(StateTesting, DefaultConstructor) {
    // ARRANGE
    State state;

    // ACT 

    // ASSERT
    EXPECT_TRUE(state.getState() == GameState::NULL_ST);

}

TEST(StateTesting, SetterAndGetter) {
    // ARRANGE
    State stateObject1;
    State stateObject2;

    // ACT
    stateObject1.setState(START_UP_ST);
    stateObject2.setState(BATTLE_ST);

    // ASSERT
    EXPECT_FALSE(stateObject1.getState() == GameState::NULL_ST);
    EXPECT_TRUE(stateObject1.getState() == GameState::START_UP_ST);
    EXPECT_EQ(stateObject2.getState(), GameState::BATTLE_ST);

}

TEST(StateTesting, Unqualified) {
    // ARRANGE
    State stateObject1;
    State stateObject2;

    // ACT
    stateObject1.setState(START_UP_ST);
    stateObject2.setState(BATTLE_ST);

    // ASSERT
    EXPECT_FALSE(stateObject1.getState() == NULL_ST);
    EXPECT_TRUE(stateObject1.getState() == START_UP_ST);
    EXPECT_EQ(stateObject2.getState(), BATTLE_ST);

}