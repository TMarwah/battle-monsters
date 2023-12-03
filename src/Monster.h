#pragma once
#include "HealthBar.h"
#include "MoveSet.h"

class Monster{
    private:
        string _type;
        HealthBar _health;
        int _basePower;
        int _baseDefense;
        std::vector<MoveSet *> _moveset;

    public:
        //constructor for monster object with stat parameters
        Monster(MonsterType _type, bool _state=true, int _basePower=0, int _baseDefense=0);
        ~Monster();
        //member function for use when attacking a monster
        int Move(Monster* defendingMonster, string _type, int _basePower);
        int attack() const;
        bool defend(int attack);

        //setup monster moveset by creating moveset vector
        void addMoves(std::vector newMoves<MoveSet *>);


    


};