#include "gtest/gtest.h"
#include "../src/States.h"
#include <iostream>


TEST(StatesTesting, enableState_disableState) {
    // ARRANGE
    States states;

    // ACT - ENABLE
    states.enableState(ACTIVE);
    states.enableState(ObjectStates::ATTACKING);

    // ASSERT - ENABLED
    EXPECT_TRUE(states.checkState(ACTIVE));
    EXPECT_TRUE(states.checkState(ObjectStates::ATTACKING));
    EXPECT_FALSE(states.checkState(DEFENDING));

    // ACT - DISABLE
    states.disableState(ACTIVE);
    states.disableState(ATTACKING);

    // ASSERT - DISABLED
    EXPECT_FALSE(states.checkState(ACTIVE));
    EXPECT_FALSE(states.checkState(ATTACKING));
    EXPECT_FALSE(states.checkState(DEFENDING));

}

TEST(StatesTesting, disableAllStates) {
    // ARRANGE
    States states;

    // ACT
    states.enableState(ACTIVE);
    states.enableState(ATTACKING);
    states.enableState(DEFENDING);

    states.disableAllStates();

    // ASSERT
    EXPECT_FALSE(states.checkState(ACTIVE));
    EXPECT_FALSE(states.checkState(ATTACKING));
    EXPECT_FALSE(states.checkState(DEFENDING));

}

TEST(StatesTesting, updateStates) {
    // ARRANGE
    States states;
    
    // ACT
    states.enableState(ACTIVE);
    states.enableState(DEFENDING);
    states.updateStates();

    // ASSERT
    EXPECT_FALSE(states.stateChanged());

}

TEST(StatesTesting, stateChanged) {
    // ARRANGE
    States states;

    // ACT
    states.enableState(ACTIVE);

    // ASSERT
    EXPECT_TRUE(states.stateChanged());

}
