#pragma once

class HealthBars
{
    private:
        int _health1;   //base health of monster1
        int _health2;   //base health of monster2

    public:
        //Constructor
        HealthBars();

        //Setters for monster's HP
        void setMonster1HP(int firstMonsterHP);
        void setMonster2HP(int secondMonsterHP);

        //Getters for monster's HP
        int getMonster1HP();
        int getMonster2HP();

        //
        void deductHealthMonster1(int incomingDamage);
        void deductHealthMonster2(int incomingDamage);
        bool checkIfZero();

};
