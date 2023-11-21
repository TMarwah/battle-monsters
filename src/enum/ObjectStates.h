#pragma once


enum ObjectStates
{
    ACTIVE,
    RUNNING,
    ATTACKING,
    DEFENDING,
    // add any new state you want above this line. as long as LAST_STATE is the
    // last state in the enum our loops will not need updating
    LAST_STATE

};