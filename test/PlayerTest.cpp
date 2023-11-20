#include "gtest/gtest.h"
#include "../src/Player.h"
#include "string"
#include <iostream>


TEST(PlayerTesting, PlayerConstructorTest) {
    Player player;

    EXPECT_EQ(player.getName(), "");
    //EXPECT_TRUE(player.getBench(), nullptr);
}

TEST(PlayerSetNameTesting, EmptyInputTest) {
    // Arrange
    Player player;
    std::string emptyName = "";

    // Act
    player.setName(emptyName);

    // Assert
    EXPECT_EQ(player.getName(), emptyName);
}

TEST(PlayerSetNameTesting, ValidInputTest) {
    // Arrange
    Player player;
    std::string validName = "SWAT Team";

    // Act
    player.setName(validName);

    // Assert
    EXPECT_EQ(player.getName(), validName);
}

   