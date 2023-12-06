#include "Skillset.h"


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
Skillset::Skillset(MonsterType type, int basePower, int baseDefense) :
    _type(type),
    _basePower(basePower),
    _baseDefense(baseDefense)
{ }


/*******************************************************************************
* SETTERS
*******************************************************************************/
void Skillset::setType(MonsterType type) {
    _type = type;

}

void Skillset::setPower(int power) {
    _basePower = power;

}

void Skillset::setDefense(int defense) {
    _baseDefense = defense;

}


/*******************************************************************************
* GETTERS
*******************************************************************************/
MonsterType Skillset::getType() const {
    return _type;

}

int Skillset::getPower() const {
    return _basePower;

}

int Skillset::getDefense() const {
    return _baseDefense;
}


/*******************************************************************************
* OVERLOADED OPERATORS
*******************************************************************************/
void Skillset::operator=(const Skillset& rhs) {
    _type = rhs._type;
    _basePower = rhs._basePower;
    _baseDefense = rhs._baseDefense;
    // TODO: add moveset copy

}