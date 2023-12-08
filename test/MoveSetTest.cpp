#include "gtest/gtest.h"
#include "../src/abstract/MoveSet.h"
#include "../src/NormalAttack.h"
#include <iostream>

TEST(MoveSetTest, ConstructorDontThrow) {
    //Arrange & Act & Assert
    MoveSet *move = nullptr;
    EXPECT_NO_THROW(move = new NormalAttack("Rock_bottom", 0.6, 50, 1));

    delete move;
}

TEST(MoveSetTest, DefaultConstructorTest) {
    //Arrange / Act
    MoveSet *move = new NormalAttack("Rock_bottom");

    //Assert
    EXPECT_EQ(move->getName(), "Rock_bottom");
    EXPECT_NEAR(move->getAccuracy(), 0.0, 0.001);
    EXPECT_NEAR(move->getDamage(), 0.0, 0.001);
    EXPECT_NEAR(move->getPriority(), 0.0, 0.001);

    delete move;
}

TEST(MoveSetTest, MoveSetterTest) {
    //Arrange & Act
    MoveSet *move = new NormalAttack("Rock_bottom", 0.6, 50, 1);

    //Assert
    EXPECT_NEAR(move->getAccuracy(), 0.6, 0.001);
    EXPECT_NEAR(move->getDamage(), 50, 0.001);
    EXPECT_NEAR(move->getPriority(), 1, 0.001);

    delete move;
}

TEST(MoveSetTest, CloneTest) {
    // Arrange 
    MoveSet *move = new NormalAttack("Rock_bottom", 0.6, 50, 1);

    // Act
    MoveSet *move_clone = move->clone();

    // Assert
    EXPECT_EQ(move->getName(), move_clone->getName());
    EXPECT_EQ(move->getDamage(), move_clone->getDamage());

    delete move;
    ASSERT_NO_THROW(delete move_clone);
}
