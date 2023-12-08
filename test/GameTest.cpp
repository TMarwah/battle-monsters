#include "gtest/gtest.h"
#include "../src/enum/GameState.h"
#include "../src/Game.h"

TEST(GameClassTests, StartUp){

    //Arrange
    Game game;
    
    //ACT
    game.init();
    
    //Assert
    EXPECT_TRUE(game.getState() == GameState::START_UP_ST);
}

TEST(GameClassTests, IsRunning){

    //Arrange
    Game game;
    
    //ACT
    game.init();
    
    //Assert
    EXPECT_TRUE(game.isRunning());
}