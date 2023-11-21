#ifndef PLAYER_H
#define PLAYER_H
#include "States.h"
#include "Event.h"

class Player : public States
{
    private:

    public:

    // VIRTUAL OVERRIDES
    void addEventHandler(Event event);
    void update();
};

#endif // PLAYER_H