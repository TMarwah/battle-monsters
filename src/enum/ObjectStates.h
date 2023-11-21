#pragma once

enum ObjectStates
{
    ACTIVE,
    RUNNING,
    START_UP,
    INIT,
    DRAFT,
    ATTACKING,
    DEFENDING,
    BATTLE,
    BATTLE_OVER,
    REPLAY,
    // add any new state you want above this line. as long as LAST_STATE is the
    // last state in the enum our loops will not need updating
    LAST_STATE

};