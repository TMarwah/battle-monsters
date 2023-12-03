#pragma once
#include "HealthBar.h"
#include "./abstract/MoveSet.h"
#include <vector>

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

        // GETTERS
        // member function to call the list of moves
        const vector<MoveSet *>& getMoves();
        int getPower();
        int getDefense();
        HealthBar& getHealthBar();
        int getHealthPoint();
        MonsterType getType();

        // SETTERS
        void setPower(int power);
        void setDefense(int defense);
        void setType(Type type);
            // will be implemented...

        //setup monster moveset by creating moveset vector
        void addMoves(std::vector newMoves<MoveSet *>);

};
