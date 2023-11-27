#include "HealthBar.h"
#include <iomanip>

HealthBars::HealthBars()
{
    _health1 = 0;
    _health2 = 0;
}

void HealthBars::setMonster1HP(int firstMonsterHP)
{
    this->_health1 = firstMonsterHP;
}

// void HealthBars::setMonster2HP(int secondMonsterHP)
// {
//     this->_health2 = secondMonsterHP;
// }

int HealthBars::getMonster1HP()
{
    return this->_health1;
}

// int HealthBars::getMonster2HP()
// {
//     return this->_health2;
// }

void HealthBars::deductHealthMonster1(int incomingDamage)
{
    this->_health1 = this->_health1 - incomingDamage;
}

// void HealthBars::deductHealthMonster2(int incomingDamage)
// {
//     this->_health2 = this->_health2 - incomingDamage;
// }

bool HealthBars::checkIfZero()
{
    if (this->_health1 == 0)
    {
        return true;
    }
    // if (this->_health2 == 0)
    // {
    //     return true;
    // }
    
    return false;
}
