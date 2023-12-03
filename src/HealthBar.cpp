#include "HealthBar.h"
#include <iomanip>

HealthBar::HealthBar()
{
    // initialize health as 100 by default
    _health = 100;
}

void HealthBar::setHP(int monsterHP)
{
    this->_health = monsterHP;
}

int HealthBar::getHP()
{
    return this->_health;
}

void HealthBar::deductHP(int incomingDamage)
{
    // if incoming damage is not greater than current HP
    if(this->_health >= incomingDamage) 
    {
        this->_health = this->_health - incomingDamage;
    }

    // if damage is fatal
    else 
    {
        _health = 0;
    }
}


bool HealthBar::isZero()
{
    if (this->_health == 0)
    {
        return true;
    }
    
    return false;
}
