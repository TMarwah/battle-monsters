#pragma once
#include "HealthBar.h"
#include "Skillset.h"
#include "./enum/MonsterType.h"
#include "./abstract/MoveSet.h"
#include "State.h"
#include <vector>
#include <iostream>

class Monster: public State{
    private:
        std::string _name;
        HealthBar _health;
        Skillset _skillset;

    public:
        //constructor for monster object with stat parameters
        Monster(const std::string& name = "nullMonster", MonsterType type=NORMAL, int power=0, int defense=0);
        // Monster(const Monster& target);
        ~Monster();

        //member function for use when attacking a monster
        // int Move(Monster* defendingMonster, MonsterType _type, int _basePower);
        Skillset& attack();
        bool defend(Skillset& enemySkillset);

        // GETTERS
        // member function to call the list of moves
        // const std::vector<MoveSet *>& getMoves() const;
        int getPower() const;
        int getDefense() const;
        MonsterType getType() const;

        const std::string& getName() const;
        int getHP() const;
        int getLostHealth() const;

        MoveSet* getMove();
        const std::vector<MoveSet *>& getMoves() const;

        Skillset& getSkillset();

        // SETTERS
        void setName(const std::string& name);
        void addMoves(const std::vector<MoveSet *>& newMoves);
        // void setPower(int power);
        // void setDefense(int defense);
        // void setType(MonsterType type);
            // will be implemented...

        //setup monster moveset by creating moveset vector
        // void addMoves(std::vector<MoveSet *> newMoves);

        // Helpers
        bool isDead();
        bool isMissed();
        void deductHP(int amount);

        // Operator Overloads
        // void operator= (const Monster& target); 

};
