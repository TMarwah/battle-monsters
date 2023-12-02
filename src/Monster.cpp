#include "Monster.h"
//Monster constructor
Monster::Monster(MonsterType _type, bool _state=true, int _basePower=0, int _baseDefense=0){}

Monster::~Monster(){
    for(unsigned int i = 0 ; i < _moveset.size() ; ++i){
        delete _moveset.at(i);
    }
    
    delete Monster;
}
int Monster::Move(Monster* defendingMonster, string _type, int _basePower){}

const Attack& Monster::attack() const{}

bool Monster::defend(const Attack& attack);

void addMoves(std::vector newMoves<MoveSet *>){
    _moveset = newMoves;
}