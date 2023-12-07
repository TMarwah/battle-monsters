#pragma once
#include "State.h"
#include "abstract/EventHandler.h"
#include "Players.h"
#include "DraftBoard.h"

class GameComponents : public State,
                       public EventHandler
{
private:
    Players _players;
    DraftBoard _draftBoard;

public:

    // GETTERS
    Players& getPlayers();
    const Players& getPlayers() const;
    // const DraftBoard& getDraftBoard() const;
    const DraftBoard* getDraftBoard() const;
    // TODO: getBench

    // VIRTUAL OVERRIDES
    void addEventHandler(const Event& event);

private:

    // PRIVATE HELPERS
    void handlePlayersSetup(const Event& event);
    void handleDraft(const Event& event);
    void handleBattle(const Event& event);
    void handlePlayAgain(const Event& event);

    bool isValidDraftInput(const std::string& input1, const std::string& input2) const;
    bool isValidBattleInput(const std::string& input1, const std::string& input2) const;

};