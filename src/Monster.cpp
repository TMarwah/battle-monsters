#include "Monster.h"

//Monster constructor
Monster::Monster(const std::string& name) : _name(name) {}

// Copy constructor
// Monster::Monster (const Monster& target):  
//     _name (target._name),
//     _type (target._type),
//     _basePower (target._basePower),
//     _baseDefense (target._baseDefense),
//     _health(target._health)
// { 
//     // for(unsigned int i = 0; i < target._moveset.size(); ++i) {
//     //     MoveSet* copyMove = target._moveset.at(i)->clone();
//     //     _moveset.push_back(copyMove);
//     // }
// }

Monster::~Monster(){
    // for(unsigned int i = 0; i < _moveset.size(); ++i){
    //     if(_moveset.at(i) != nullptr) {
    //         delete _moveset.at(i);
    //     }
    // }
}

// int Monster::Move(Monster* defendingMonster, MonsterType _type, int _basePower) {
//     // FIXME: implement
//     return 0;
// }

int Monster::attack() const{
    // currently a stub of 10
    return 10;
}

bool Monster::defend(int attack) {

    // use battle calculator to figure out final
    // value to deduct from health
    // deductHP(attack);
    
    // return true/false if monster died from attack
    return true;
}

// void Monster::addMoves(std::vector <MoveSet *> newMoves){
//     // delete moves before assigning new moves
//     // for(unsigned int i = 0; i < _moveset.size(); ++i) {
//     //     if(_moveset.at(i) != nullptr) {
//     //         delete _moveset.at(i);
//     //     }
//     // }

//     // _moveset = newMoves;
// }


// GETTERS
// const std::vector<MoveSet *>& Monster::getMoves() const{
//     return _moveset;
// }

// int Monster::getPower() const{
//     return _basePower;
// }

// int Monster::getDefense() const{
//     return _baseDefense;
// }

// HealthBar& Monster::getHealthBar(){
//     return _health;
// }

// int Monster::getHealthPoint() const{
//     return _health.getHP();
// }

// MonsterType Monster::getType() const{
//     return _type;
// }

void Monster::setName(const std::string& name) {
    _name = name;
}

const std::string& Monster::getName() const{
    return _name;
}

int Monster::getHP() const {
    return _health.getHP();
}
// Setters

// void Monster::setPower(int power) {
//     _basePower = power;
// }

// void Monster::setDefense(int defense) {
//     _baseDefense = defense;
// }

// void Monster::setType(MonsterType type) {
//     _type = type;
// }


// Helpers
bool Monster::isDead() {
    return _health.isZero();
}

void Monster::deductHP(int amount) {
    _health.deductHP(amount);
}

// Overloaded Operators
void Monster::operator= (const Monster& target) {
    _name = target._name;
    // _type = target._type;
    // _basePower = target._basePower;
    // _baseDefense = target._baseDefense;
    _health = target._health;
    _skillset = target._skillset;

    // for(unsigned int i = 0; i < _moveset.size(); ++i) {
    //     if(_moveset.at(i) != nullptr) {
    //         delete _moveset.at(i);
    //     }
    // }

    // for(unsigned int i = 0; i < target._moveset.size(); ++i) {
    //     MoveSet* copyMove = target._moveset.at(i)->clone();
    //     _moveset.push_back(copyMove);
    // }
}
