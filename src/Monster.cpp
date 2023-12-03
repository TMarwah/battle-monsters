#include "Monster.h"
//Monster constructor
Monster::Monster(MonsterType _type, bool _state=true, int _basePower=0, int _baseDefense=0){}

Monster::~Monster(){
    for(unsigned int i = 0 ; i < _moveset.size() ; ++i){
        delete _moveset.at(i);
    }
    
    delete Monster;
}

int Monster::Move(Monster* defendingMonster, string _type, int _basePower) {

}

int Monster::attack() const{

    // currently a stub of 10
    return 10;
}

bool Monster::defend(int attack) {

    // use battle calculator to figure out final
    // value to deduct from health
    this->deductHP(attack);
    
    // return true/false if monster died from attack
    return true;
}

void Monster::addMoves(std::vector newMoves<MoveSet *>){
    _moveset = newMoves;
}


// GETTERS
const vector<MoveSet *>& Monster::getMoves() {
    return _moveset;
}

int Monster::getPower() {
    return _basePower;
}

int Monster::getDefense() {
    return _baseDefense;
}

HealthBar& Monster::getHealthBar() {
    return _health;
}

int Monster::getHealthPoint() {
    return _health.getHP();
}

MonsterType Monster::getType() {
    return _type;
}

// Setters

void setPower(int power) {
    _basePower = power;
}

void setDefense(int defense) {
    _baseDefense = defense;
}

void setType(Type type) {
    _type = type;
}