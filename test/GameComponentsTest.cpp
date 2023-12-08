#include "gtest/gtest.h"
#include "../src/GameComponents.h"


TEST(GameComponentsTests, GetPlayers){

    //Arrange
    GameComponents gameComponents;
    
    //ACT
    
    //Assert
    EXPECT_NO_THROW(gameComponents.getPlayers());
}

TEST(GameComponentsTests, DraftBoard){

    //Arrange
    GameComponents gameComponents;
    
    //ACT
    
    //Assert
    EXPECT_NO_THROW(gameComponents.getDraftBoard());
}