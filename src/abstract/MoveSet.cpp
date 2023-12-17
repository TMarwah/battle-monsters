#include "MoveSet.h"
#include <iomanip>

//Default constructor
MoveSet::MoveSet(const std::string& name, float accuracy, int damage, int priority) :
    _moveName(name),
    _defaultAccuracy(accuracy),
    _defaultDamage(damage),
    _priority(priority)
{ }

// setters
void MoveSet::setAccuracy(float accuracy){
    this->_defaultAccuracy = accuracy;
}

void MoveSet::setDamage(int damage){
    this->_defaultDamage = damage;
}

void MoveSet::setPriority(int priority){
    this->_priority = priority;
}

float MoveSet::getAccuracy() const{
    std::setprecision(2);
    return _defaultAccuracy;

}

int MoveSet::getDamage() const{
    return _defaultDamage;
}

int MoveSet::getPriority() const{
    return _priority;
}

const std::string& MoveSet::getName() const{
    return _moveName;
}

// Type Compatibility
/*
 - NORMAL = * All Types ( 1.25 attack / 1.0 defense )
 - FIRE > AIR ( 1.5 attack / 0.5 defense ); FIRE < WATER ( 0.5 attack / 1.5 defense )
 - WATER > FIRE ( 1.5 attack / 0.5 defense ); WATER < EARTH ( 0.5 attack / 1.5 defense )
 - EARTH > WATER ( 1.5 attack / 0.5 defense ); EARTH < AIR ( 0.5 attack / 1.5 defense )
 - AIR > EARTH ( 1.5 attack / 0.5 defense ); AIR < FIRE ( 0.5 attack / 1.5 defense )
*/
float MoveSet::getCompatibility(MonsterType attackType, MonsterType defenseType) const {
    return CompatibilityInterface::getCompatibility(attackType, defenseType);
}