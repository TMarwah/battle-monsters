#include "gtest/gtest.h"
#include "../src/DraftBoard.h"


// Test init() method using checkState() method
TEST(DraftBoardTests, DraftBoardInit){
    // Arrange
    DraftBoard draftBoard;
    
    // ACT
    std::string name1 = draftBoard.at(0).getName();
    std::string name2 = draftBoard.at(1).getName();
    
    // Assert
    EXPECT_TRUE(name1 == "Andrewsaurus");
    EXPECT_TRUE(name2 == "Willzilla");
    EXPECT_EQ(draftBoard.size(), 4);

}