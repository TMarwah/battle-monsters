#include "gtest/gtest.h"
#include "../src/MoveSet.h"
#include <iostream>


TEST(MoveSetTest, DefaultConstructorTest) {
    //Arrange / Act
    MoveSet move;

    //Assert
    EXPECT_NEAR(move.GetAccuracy(), 0.0, 0.001);
    EXPECT_NEAR(move.GetDamage(), 0, 0.001);
    EXPECT_NEAR(move.GetPriority(), 0, 0.001);
}

TEST(MoveSetTest, MoveSetterTest1) {
    //Arrange
    MoveSet move;

    //Act
    move.SetAccuracy(0.6);
    move.SetDamage(50);
    move.SetPriority(2);

    //Assert
    EXPECT_NEAR(move.GetAccuracy(), 0.6, 0.001);
    EXPECT_NEAR(move.GetDamage(), 50, 0.001);
    EXPECT_NEAR(move.GetPriority(), 2, 0.001);
}

TEST(MoveSetTest, MoveSetterTest2) {
    //Arrange
    MoveSet move;

    //Act
    move.SetAccuracy(0.10);
    move.SetDamage(25);
    move.SetPriority(2);

    //Assert
    EXPECT_NEAR(move.GetAccuracy(), 0.10, 0.001);
    EXPECT_NEAR(move.GetDamage(), 25, 0.001);
    EXPECT_NEAR(move.GetPriority(), 2, 0.001);
}

TEST(MoveSetTest, MoveSetterTest3) {
    //Arrange
    MoveSet move;

    //Act
    move.SetAccuracy(0.78);
    move.SetDamage(20);
    move.SetPriority(1);

    //Assert
    EXPECT_NEAR(move.GetAccuracy(), 0.78, 0.001);
    EXPECT_NEAR(move.GetDamage(), 20, 0.001);
    EXPECT_NEAR(move.GetPriority(), 1, 0.001);
}

   