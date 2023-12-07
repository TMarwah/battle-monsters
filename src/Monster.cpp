#include "Monster.h"

//Monster constructor
Monster::Monster(const std::string& name, MonsterType type, int power, int defense) : 
    _name(name) 
{
    _skillset.setType(type);
    _skillset.setPower(power);
    _skillset.setDefense(defense);

    setState(START_UP_ST);
}

// Copy constructor
// Monster::Monster (const Monster& target):  
//     _name (target._name),
//     _skillset(target._skillset)
// { }

Monster::~Monster(){
    // for(unsigned int i = 0; i < _skillset.getMoves().size(); ++i){
    //     if(_skillset.getMoves().at(i) != nullptr) {
    //         delete _skillset.getMoves().at(i);
    //     }
    // }
}

// int Monster::Move(Monster* defendingMonster, MonsterType _type, int _basePower) {
//     // FIXME: implement
//     return 0;
// }

Skillset& Monster::attack() {
    setState(BATTLE_ST);
    
    if(FLAG_ON) {
        std::cout << "Monster::attack" << "\n";
    }
    return _skillset;
}

bool Monster::defend(Skillset& enemySkillset) {

    if(FLAG_ON) {
        std::cout << "Monster::defend" << "\n";
    }

    // use battle calculator to figure out final
    // value to deduct from health
    // .getMove() uses the move selected
        // skillMethod(MonsterType baseType, int baseAttack, int baseOpponentDefense)
    MonsterType enemyType = enemySkillset.getType();
    int enemyPower = enemySkillset.getPower();


    int damage = enemySkillset.getMove()->skillMethod(enemyType, enemyPower, _skillset.getDefense());
    // if the state of the skill is set to the ATTACK_MISSED_ST, set up the flag
    bool isSkillMissed = ( enemySkillset.getMove()->getState() == GameState::ATTACK_MISSED_ST );

    deductHP(damage);

    // if attack is missed, remove flag from the skill and set flag on the skillset of enemy
    if(isSkillMissed) {
        enemySkillset.getMove()->setState(NULL_ST);
        enemySkillset.setState(ATTACK_MISSED_ST);
    }

    if(FLAG_ON) {
        std::cout << "\n\ngetHP(): " << getHP() << "\n\n";
    }

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

int Monster::getLostHealth() const {
    return _health.getLostHealth();
}

int Monster::getPower() const {
    return _skillset.getPower();
}

int Monster::getDefense() const {
    return _skillset.getDefense();
}

MoveSet* Monster::getMove() {
    return _skillset.getMove();
}

const std::vector<MoveSet *>& Monster::getMoves() const {
    return _skillset.getMoves();
}


// Helpers
bool Monster::isDead() {
    return _health.isZero();
}

bool Monster::isMissed() {
    bool missed = ( _skillset.getState() == GameState::ATTACK_MISSED_ST );
    if(missed) {
        _skillset.setState(NULL_ST);
    }

    return missed;
}

void Monster::deductHP(int amount) {
    _health.deductHP(amount);
}

// Overloaded Operators
// void Monster::operator= (const Monster& target) {
//     _name = target._name;
//     _health = target._health;
//     _skillset = target._skillset;
// }
