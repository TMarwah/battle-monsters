#pragma once
#include "State.h"
#include "abstract/EventHandler.h"
#include "Player.h"
#include "definitions/Definitions.h"
#include "enum/EventType.h"


class Players : public State, public EventHandler
{
    Player* _players;

public:
    // CONSTRUCTOR & DESTRUCTOR
    Players();
    ~Players();

    // MUTATORS
    void setNames(const Event& event);
    void fight(Monster& monster1, Monster& monster2);
    void reset();
    void update();

    // ACCESSORS
    Player& getPlayer(unsigned index);
    // Player& getPlayer(unsigned index) const;
    // const Player& getPlayer(unsigned index) const;

    void addEventHandler(const Event& event);
    void handleDraft(const Event& event);
    void handleBattle(const Event& event);

};