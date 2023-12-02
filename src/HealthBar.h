#pragma once

class HealthBar
{
    private:
        int _health1;   //base health of monster1

    public:
        //Constructor
        HealthBar();

        //Setters for monster's HP
        void setMonster1HP(int firstMonsterHP);

        //Getters for monster's HP
        int getMonster1HP();

        //
        void deductHealthMonster1(int incomingDamage);
        bool checkIfZero();

};
