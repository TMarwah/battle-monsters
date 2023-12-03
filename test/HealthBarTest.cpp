#include "gtest/gtest.h"
#include "../src/HealthBar.h"
#include <iostream>

TEST(HealthBarTest, DefaultConstructorTest)
{
    //Arrange / Act
    HealthBar _healthbar;

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
}

TEST(HealthBarTest, Monster1HealthSetter_1)
{
    //Arrange 
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(50);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 50);
}

TEST(HealthBarTest, Monster1HealthSetter_2)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(150);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 150);
}

TEST(HealthBarTest, ReduceMonster1Health_1)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(50);
    _healthbar.deductHealthMonster1(25);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 25);
}

TEST(HealthBarTest, ReduceMonster1Health_2)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(59);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 91);
}

TEST(HealthBarTest, CheckForZeroHP_monster1)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(150);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
    EXPECT_TRUE(_healthbar.checkIfZero());
}

TEST(HealthBarTest, CheckForZeroHP_monster1_1) //suppose to fail
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(100);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
    EXPECT_TRUE(_healthbar.checkIfZero());
}
