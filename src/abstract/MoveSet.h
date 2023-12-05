#pragma once
#include <string>
#include "./enum/MonsterType.h"


class MoveSet{
    private:
        std::string _moveName; //name of the move
        float _defaultAccuracy; //0-1 float accuracy value
        int _defaultDamage; //base damage of move before scaling types
        int _priority; //"speed" stat determining move order
    
    public:
        //Virtual function to be implemented by inherited class
        virtual void skillMethod(MonsterType baseType=NORMAL, int baseAttack=0, int baseOpponentDefense=0) = 0;
        virtual MoveSet* clone() const = 0;

        //Constructor
        MoveSet(const std::string& _moveName, float accuracy=0.0, int damage=0, int priority=0);

        //Setters for move stats
        void setAccuracy(float accuracy);
        void setDamage(int damage);
        void setPriority(int priority);

        //Getters for move stats
        const std::string& getName() const;
        float getAccuracy() const;
        int getDamage() const;
        int getPriority() const;
};
