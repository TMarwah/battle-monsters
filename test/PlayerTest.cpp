#include "gtest/gtest.h"
#include "../src/Player.h"
#include "string"
#include <iostream>


TEST(PlayerTesting, Constructor) {
    Player player;

    EXPECT_EQ(player.getName(), "");
    //EXPECT_TRUE(player.getBench(), nullptr);
}

TEST(PlayerTesting, EmptyInputTest) {
    // Arrange
    Player player;
    std::string emptyName = "";

    // Act
    player.setName(emptyName);

    // Assert
    EXPECT_EQ(player.getName(), emptyName);
}

TEST(PlayerTesting, ValidInputTest) {
    // Arrange
    Player player;
    std::string validName = "SWAT Team";

    // Act
    player.setName(validName);

    // Assert
    EXPECT_EQ(player.getName(), validName);
}

TEST(PlayerTesting, playerDefeated) {
    // Arrange
    Player player;

    // Act
    player.setState(GameState::DEFEATED_ST);

    // Assert
    EXPECT_TRUE(player.isDefeated());
}

TEST(PlayerTesting, reset) {
    // Arrange
    Player player;

    // Act
    player.setState(GameState::DEFEATED_ST);
    player.reset();

    // Assert
    EXPECT_FALSE(player.isDefeated());
}