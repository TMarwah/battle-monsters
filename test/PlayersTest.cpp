#include "gtest/gtest.h"
#include "../src/Players.h"
#include "../src/Event.h"


TEST(PlayersTesting, SetNames) {
    // Arrange
    Players players;
    Event event;
    std::string name1 = "Larry";
    std::string name2 = "Moe";
    
    // Act
    event.data1 = "Larry";
    event.data2 = "Moe";
    players.setNames(event);

    // Assert
    EXPECT_EQ(players.getPlayer(0).getName(), name1);
    EXPECT_EQ(players.getPlayer(1).getName(), name2);
}

TEST(PlayersTesting, Update) {

    // Arrange
    Players players;
    
    // Act
    players.getPlayer(0).setState(DEFEATED_ST);

    // Assert
    EXPECT_TRUE(players.getPlayer(0).isDefeated());

}