#include "gtest/gtest.h"
#include "../src/Player.h"
#include <iostream>


TEST(PlayerTesting, player_construction_test) {
    Player player;

    EXPECT_EQ(player.getName(), "");
    //EXPECT_TRUE(player.getBench(), nullptr);
}

   