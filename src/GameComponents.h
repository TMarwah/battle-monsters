#pragma once
#include "State.h"
#include "abstract/EventHandler.h"
#include <Players.h>


class GameComponents : public State,
                       public EventHandler
{
private:
    Players _players;
    // TODO: Bench _benches (BENCH_SIZE)
    // TODO: Bench _draftBench (size of NUM_OF_PLAYERS * BENCH_SIZE)

public:

    // GETTERS
    const Players& getPlayers() const;
    // TODO: getBench

    // VIRTUAL OVERRIDES
    void addEventHandler(const Event& event);

private:

    // PRIVATE HELPERS
    void handlePlayersSetup(const Event& event);
    void handleDraft(const Event& event);
    void handleBattle(const Event& event);

};