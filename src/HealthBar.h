#pragma once

class HealthBar
{
    private:
        int _health;   //base health of monster1

    public:
        //Constructor
        HealthBar();

        //Setters for monster's HP
        void setHP(int firstMonsterHP);

        //Getters for monster's HP
        int getHP();

        //
        bool deductHP(int incomingDamage);
        bool isZero();

};
