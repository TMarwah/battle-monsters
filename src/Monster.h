#pragma once
#include "HealthBar.h"
#include "./enum/MonsterType.h"
#include "./abstract/MoveSet.h"
#include <vector>

class Monster{
    private:
        std::string _name;
        MonsterType _type;
        HealthBar _health;
        int _basePower;
        int _baseDefense;
        std::vector<MoveSet *> _moveset;

    public:
        //constructor for monster object with stat parameters
        Monster(const std::string& name, MonsterType type=NORMAL, int basePower=0, int baseDefense=0);
        ~Monster();

        //member function for use when attacking a monster
        int Move(Monster* defendingMonster, MonsterType _type, int _basePower);
        int attack() const;
        bool defend(int attack);

        // GETTERS
        // member function to call the list of moves
        const std::vector<MoveSet *>& getMoves() const;
        int getPower() const;
        int getDefense() const;
        HealthBar& getHealthBar() const;
        int getHealthPoint() const;
        MonsterType getType() const;
        const std::string& getName() const;

        // SETTERS
        void setPower(int power);
        void setDefense(int defense);
        void setType(MonsterType type);
            // will be implemented...

        //setup monster moveset by creating moveset vector
        void addMoves(std::vector<MoveSet *> newMoves);

        // Helpers
        bool isDead();
        void deductHP(int amount);

};
