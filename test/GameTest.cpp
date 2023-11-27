#include "gtest/gtest.h"
#include "../src/enum/GameState.h"
#include "../src/Game.h"

// Test if constructor generates _players member variable
// TEST(GameClassTests, testConstructor) {
//     // call constructor
//     Game game;
//     // if nullptr, it will return false; therefore terminate
//     ASSERT_TRUE(game.getPlayers()); 
// }

// Test init() method using checkState() method
TEST(GameClassTests, testInitMethod){
    //Arrange
    Game game;
    //ACT
    game.init();
    //Assert
    EXPECT_TRUE(game.isRunning());
    EXPECT_TRUE(game.getState() == GameState::START_UP_ST);
}

// Test GetInput() method 
TEST(GameClassTests, testGetInputMethodToSetName) {
    //Arrange
    Game game;

    //ACT
    game.init();
    if(game.isRunning()) {
        game.getInput();
    }

    std::string name1 = game.getPlayers().getPlayer(0).getName();
    std::string name2 = game.getPlayers().getPlayer(1).getName();

    //Assert
    EXPECT_TRUE(name1 != "" | name2 != "");
}