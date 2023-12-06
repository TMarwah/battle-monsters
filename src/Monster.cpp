#include "Monster.h"

//Monster constructor
Monster::Monster(const std::string& name, MonsterType type, int power, int defense) : 
    _name(name) 
{
    _skillset.setType(type);
    _skillset.setPower(power);
    _skillset.setDefense(defense);
}

// Copy constructor
Monster::Monster (const Monster& target):  
    _name (target._name),
    _skillset(target._skillset)
{ }

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

Skillset& Monster::attack() {

    std::cout << "Monster::attack" << "\n";
    // currently a stub of 10
    return _skillset;
}

bool Monster::defend(Skillset& enemySkillset) {

    std::cout << "Monster::defend" << "\n";

    // use battle calculator to figure out final
    // value to deduct from health
    deductHP(enemySkillset.getPower() - getDefense() * 0.3);
    std::cout << "\n\ngetHP(): " << getHP() << "\n\n";
    // return true/false if monster died from attack
    return true;
}

// SETTERS
void Monster::setName(const std::string& name) {
    _name = name;
}

void Monster::addMoves(const std::vector<MoveSet *>& newMoves) {
    _skillset.addMoves(newMoves);
}


// GETTERS
const std::string& Monster::getName() const{
    return _name;
}

int Monster::getHP() const {
    return _health.getHP();
}

Skillset& Monster::getSkillset() {
    return _skillset;
}

MonsterType Monster::getType() const {
    return _skillset.getType();
}

int Monster::getPower() const {
    return _skillset.getPower();
}

int Monster::getDefense() const {
    return _skillset.getDefense();
}

const std::vector<MoveSet *>& Monster::getMoves() const {
    return _skillset.getMoves();
}


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
    _health = target._health;
    _skillset = target._skillset;
}
