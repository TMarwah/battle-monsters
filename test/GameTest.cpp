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

// Test Init() method using checkState() method
TEST(GameClassTests, testInitMethod){
    //Arrange
    Game game;
    game.Init();
    //Assert
    EXPECT_TRUE(game.checkState(ACTIVE));
}