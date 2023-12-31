#pragma once

class HealthBar
{
    private:
        int _health;   //base health of monster1
        int _healthLost;

    public:
        //Constructor
        HealthBar();

        //Setters for monster's HP
        void setHP(int firstMonsterHP);

        //Getters for monster's HP
        int getHP() const;
        int getLostHealth() const;

        //
        bool deductHP(int incomingDamage);
        bool isZero();

        // OPERATOR OVERLOADS
        void operator=(const HealthBar& rhs);

};
