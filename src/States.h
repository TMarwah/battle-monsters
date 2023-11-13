#ifndef STATES_H
#define STATES_H
#include <map>
#include "enum/ObjectStates.h"


class States
{

protected:
    std::map<ObjectStates, bool> _states;
    std::map<ObjectStates, bool> _prevStates;


public:
    // CONSTRUCTOR
    States();   // adds all the different ObjectStates and init them as false

    // MUTATORS
    virtual void disableState(ObjectStates state);
    virtual void enableState(ObjectStates state);
    void disableAllStates();
    void updateStates();

    // ACCESSORS
    std::map<ObjectStates, bool> currentStates() const;
    bool checkState(ObjectStates state) const;
    bool stateChanged() const;

    // OPERATOR OVERLOADS
    States& operator=(const States& rhs);

};


#endif // STATES_H