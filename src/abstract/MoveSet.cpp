#include "MoveSet.h"
#include <iomanip>
//Default constructor
MoveSet::MoveSet(std::string name, float accuracy, int damge, int priority) :
    _moveName(name),
    _defaultAccuracy(accuracy),
    _defaultDamage(damage),
    _priority(priority)
{ }

void MoveSet::SetAccuracy(float accuracy){
    this->_defaultAccuracy = accuracy;
}

void MoveSet::SetDamage(int damage){
    this->_defaultDamage = damage;
}

void MoveSet::SetPriority(int priority){
    this->_priority = priority;
}

float MoveSet::GetAccuracy(){
    std::setprecision(2);
    return _defaultAccuracy;

}

int MoveSet::GetDamage(){
    return _defaultDamage;
}

int MoveSet::GetPriority(){
    return _priority;
}