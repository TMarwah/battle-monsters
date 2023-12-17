#pragma once

// Type Compatibility
/*
 - NORMAL = * All Types ( 1.0 attack / defense )
 - FIRE > AIR ( 1.5 attack / 0.5 defense ); FIRE < WATER ( 0.5 attack / 1.5 defense )
 - WATER > FIRE ( 1.5 attack / 0.5 defense ); WATER < EARTH ( 0.5 attack / 1.5 defense )
 - EARTH > WATER ( 1.5 attack / 0.5 defense ); EARTH < AIR ( 0.5 attack / 1.5 defense )
 - AIR > EARTH ( 1.5 attack / 0.5 defense ); AIR < FIRE ( 0.5 attack / 1.5 defense )
*/

enum MonsterType
{
    NULL_TYPE,
    NORMAL,
    FIRE,
    WATER,
    EARTH,
    AIR
};
