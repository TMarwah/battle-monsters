#pragma once

enum GameState
{
    // ACTIVE_ST,
    // RUNNING_ST,
    START_UP_ST,
    PLAYERS_SETUP_ST,
    DRAFT_ST,
    // ATTACKING_ST,
    // DEFENDING_ST,
    BATTLE_ST,
    BATTLE_OVER_ST,
    PLAY_AGAIN_ST,
    QUIT_ST,
    DEFEATED_ST,
    NULL_ST,
    // add any new state you want above this line. as long as LAST_STATE is the
    // last state in the enum our loops will not need updating
    LAST_ST

};