#include "gtest/gtest.h"
#include "../src/HealthBar.h"
#include <iostream>

TEST(HealthBarsTest, DefaultConstructorTest)
{
    //Arrange / Act
    HealthBars _healthbar;

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
    // EXPECT_EQ(_healthbar.getMonster2HP(), 0);
}

TEST(HealthBarsTest, Monster1HealthSetter_1)
{
    //Arrange 
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(50);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 50);
}

TEST(HealthBarsTest, Monster1HealthSetter_2)
{
    //Arrange
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(150);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 150);
}

// TEST(HealthBarsTest, Monster2HealthSetter_1)
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(50);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 50);
// }

// TEST(HealthBarsTest, Monster2HealthSetter_2)
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(150);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 150);    
// }

TEST(HealthBarsTest, ReduceMonster1Health_1)
{
    //Arrange
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(50);
    _healthbar.deductHealthMonster1(25);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 25);
}

TEST(HealthBarsTest, ReduceMonster1Health_2)
{
    //Arrange
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(59);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 91);
}

// TEST(HealthBarsTest, ReduceMonster2Health_1)
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(50);
//     _healthbar.deductHealthMonster2(25);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 25);
// }

// TEST(HealthBarsTest, ReduceMonster2Health_2)
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(150);
//     _healthbar.deductHealthMonster2(59);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 91);
// }

TEST(HealthBarsTest, CheckForZeroHP_monster1)
{
    //Arrange
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(150);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
    EXPECT_TRUE(_healthbar.checkIfZero());
}

TEST(HealthBarsTest, CheckForZeroHP_monster1_1) //suppose to fail
{
    //Arrange
    HealthBars _healthbar;

    //Act
    _healthbar.setMonster1HP(150);
    _healthbar.deductHealthMonster1(100);

    //Assert
    EXPECT_EQ(_healthbar.getMonster1HP(), 0);
    EXPECT_TRUE(_healthbar.checkIfZero());
}

// TEST(HealthBarsTest, CheckForZeroHP_monster2)
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(150);
//     _healthbar.deductHealthMonster2(150);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 0);
//     EXPECT_TRUE(_healthbar.checkIfZero());
// }

// TEST(HealthBarsTest, CheckForZeroHP_monster2_1) //suppose to fail
// {
//     //Arrange
//     HealthBars _healthbar;

//     //Act
//     _healthbar.setMonster2HP(150);
//     _healthbar.deductHealthMonster2(149);

//     //Assert
//     EXPECT_EQ(_healthbar.getMonster2HP(), 0);
//     EXPECT_TRUE(_healthbar.checkIfZero());
// }
