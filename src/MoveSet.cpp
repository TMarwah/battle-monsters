#include "MoveSet.h"
#include <iomanip>
//Default constructor
MoveSet::MoveSet(){
    _defaultAccuracy = 0.0;
    _defaultDamage = 0;
    _priority = 0;
}

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