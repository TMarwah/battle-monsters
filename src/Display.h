#pragma once
#include <iostream>
#include "States.h"
#include "Player.h"


class Display : public States
{
public:
    void render(const Player& player1, const Player& player2) const;

};