#include "GameComponents.h"


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
const Players& GameComponents::getPlayers() const {
    return _players;
}


/*******************************************************************************
* VIRTUAL OVERRIDES
*******************************************************************************/
void GameComponents::addEventHandler(const Event& event) {

    switch(getState())
    {
        case PLAYERS_SETUP_ST:
            handlePlayersSetup(event);
            break;

        case DRAFT_ST:
            handleDraft(event);
            break;

        case BATTLE_ST:
            handleBattle(event);
            break;

        // TODO: create RESET case and actions if user is REPLAY-ing

    }
}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
void GameComponents::handlePlayersSetup(const Event& event) 
{
    // set both player names
    if(event.eventType == EventType::SET_NAMES) {
        _players.setNames(event);
        setState(NULL_ST);
    }
}


void GameComponents::handleDraft(const Event& event) 
{
    // TODO: handle DRAFT_ST events:
    // remove monster from draftBench until both player1 bench and player2
    // bench are equal to BENCH_SIZE. Then turn off DRAFT_ST

    if(event.eventType == EventType::DRAFT_SELECTION) {
        if(event.data1 == "qq") {
            setState(NULL_ST);
        }
    }

}


void GameComponents::handleBattle(const Event& event) {

    // TODO: handle BATTLE_ST events
    // keep battling until one of the players has no monsters left
    
    if(event.eventType == EventType::ATTACK) {
        if(event.data1 == "qq") {
            setState(NULL_ST);
        }
    }

}
