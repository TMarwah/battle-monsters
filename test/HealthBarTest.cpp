#include "gtest/gtest.h"
#include "../src/HealthBar.h"
#include <iostream>

TEST(HealthBarTest, DefaultConstructorTest)
{
    //Arrange / Act
    HealthBar _healthbar;

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 100);
}

TEST(HealthBarTest, MonsterHealthSetter)
{
    //Arrange 
    HealthBar _healthbar;

    //Act
    _healthbar.setHP(50);

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 50);
}

TEST(HealthBarTest, ReduceMonsterHealth)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setHP(50);
    _healthbar.deductHP(25);

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 25);
}

TEST(HealthBarTest, CheckForZeroHP)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setHP(150);
    _healthbar.deductHP(150);

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 0);
    EXPECT_TRUE(_healthbar.isZero());
}

TEST(HealthBarTest, CheckForZeroHPWhenFatalDamage)
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setHP(100);
    _healthbar.deductHP(150);

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 0);
    EXPECT_TRUE(_healthbar.isZero());
}

TEST(HealthBarTest, CheckForNonZeroHP) 
{
    //Arrange
    HealthBar _healthbar;

    //Act
    _healthbar.setHP(150);
    _healthbar.deductHP(100);

    //Assert
    EXPECT_EQ(_healthbar.getHP(), 50);
    EXPECT_FALSE(_healthbar.isZero());
}

TEST(HealthBarTest, AssignmentOperatorOverload) 
{
    //Arrange
    HealthBar _healthbar;
    HealthBar _copy_healthbar;

    //Act
    _healthbar.setHP(150);
    _copy_healthbar.setHP(0);

    _copy_healthbar = _healthbar;

    //Assert
    EXPECT_EQ(_healthbar.getHP(), _copy_healthbar.getHP());
    EXPECT_FALSE(_healthbar.isZero() && _copy_healthbar.isZero());
}
