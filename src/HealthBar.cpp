#include "HealthBar.h"
#include <iomanip>

HealthBar::HealthBar()
{
    _health1 = 0;
}

void HealthBar::setMonster1HP(int firstMonsterHP)
{
    this->_health1 = firstMonsterHP;
}

int HealthBar::getMonster1HP()
{
    return this->_health1;
}

void HealthBar::deductHealthMonster1(int incomingDamage)
{
    this->_health1 = this->_health1 - incomingDamage;
}


bool HealthBar::checkIfZero()
{
    if (this->_health1 == 0)
    {
        return true;
    }
    
    return false;
}
