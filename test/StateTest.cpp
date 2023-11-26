#include "gtest/gtest.h"
#include "../src/State.h"
#include "../src/enum/GameState.h"


TEST(StateTesting, DefaultConstructorTest) {
    // ARRANGE
    State state;

    // ACT 

    // ASSERT
    EXPECT_TRUE(state.getState() == GameState::NULL_ST);

}

TEST(StateTesting, setterAndGetterTest) {
    // ARRANGE
    State stateObject1;
    State stateObject2;

    // ACT
    stateObject1.setState(START_UP_ST);
    stateObject2.setState(BATTLE_ST);

    // ASSERT
    EXPECT_TRUE(stateObject1.getState() == START_UP_ST);
    EXPECT_TRUE(stateObject2.getState() == BATTLE_ST);

}
