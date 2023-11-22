#pragma once

class MoveSet{
    private:
        float _defaultAccuracy; //0-1 float accuracy value
        int _defaultDamage; //base damage of move before scaling types
        int _priority; //"speed" stat determining move order
    
    public:
        //Virtual function to be implemented by inherited class
        //virtual void SkillMethod() = 0;

        //Constructor
        MoveSet();

        //Setters for move stats
        void SetAccuracy(float accuracy);
        void SetDamage(int damage);
        void SetPriority(int priority);

        //Getters for move stats
        float GetAccuracy();
        int GetDamage();
        int GetPriority();

};