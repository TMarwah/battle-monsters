#include "gtest/gtest.h"
#include "../src/enum/ObjectStates.h"
#include "../src/Game.h"

// Test if constructor generates _players member variable
TEST(GameClassTests, testConstructor) {
    // call constructor
    Game game;
    // if nullptr, it will return false; therefore terminate
    ASSERT_TRUE(game.getPlayers()); 
}

// Test init() method using checkState() method
TEST(GameClassTests, testInitMethod){
    //Arrange
    Game game;
    //ACT
    game.init();
    //Assert
    EXPECT_TRUE(game.checkState(ACTIVE));
}

// Test GetInput() method 
TEST(GameClassTests, testGetInputMethod) {
    //Arrange
    Game game;
    // further Player class implementation required...

    //ACT
    // game.GetInput();

    //Assert
    EXPECT_TRUE(false);
}

TEST(GameClassTests, testUpdateMethod) {
    //Arrange
    Game game;

    //Act
    game.update();

    //Assert
    EXPECT_TRUE(game.stateChanged());
}

TEST(GameClassTests, testDrawMethod) {
    // further visual representation functions required

    EXPECT_TRUE(false);
}