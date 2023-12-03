#include "MoveSet.h"
#include <iomanip>

//Default constructor
MoveSet::MoveSet(const std::string& name, float accuracy, int damage, int priority) :
    _moveName(name),
    _defaultAccuracy(accuracy),
    _defaultDamage(damage),
    _priority(priority)
{ }

void MoveSet::setAccuracy(float accuracy){
    this->_defaultAccuracy = accuracy;
}

void MoveSet::setDamage(int damage){
    this->_defaultDamage = damage;
}

void MoveSet::setPriority(int priority){
    this->_priority = priority;
}

float MoveSet::getAccuracy(){
    std::setprecision(2);
    return _defaultAccuracy;

}

int MoveSet::getDamage(){
    return _defaultDamage;
}

int MoveSet::getPriority(){
    return _priority;
}

const std::string& MoveSet::getName() {
    return _moveName;
}