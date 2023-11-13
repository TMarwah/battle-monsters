#include "States.h"


/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/
States::States()
{
    // initialize all states to false
    // using LAST_STATE in the loop is why we keep LAST_STATE as the last state
    for(int state = 0; state < LAST_STATE; ++state)
        _states[static_cast<ObjectStates>(state)] = false;

    _prevStates = _states;

}


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void States::disableState(ObjectStates state)
{
    _states[state] = false;

}

void States::enableState(ObjectStates state)
{
    _states[state] = true;

}

void States::disableAllStates()
{
    for(int state = 0; state < LAST_STATE; ++state)
        _states[static_cast<ObjectStates>(state)] = false;

}

void States::updateStates()
{
    _prevStates = _states;

}


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
std::map<ObjectStates, bool> States::currentStates() const
{
    return _states;

}

bool States::checkState(ObjectStates state) const
{
    return _states.at(state);

}

bool States::stateChanged() const 
{
    return _prevStates != _states;

}


/*******************************************************************************
* OPERATOR OVERLOADS
*******************************************************************************/
States& States::operator=(const States& rhs)
{
    for(int i = 0; i < LAST_STATE; ++i)
        _states[static_cast<ObjectStates>(i)] = rhs._states.at(static_cast<ObjectStates>(i));

    return *this;

}
