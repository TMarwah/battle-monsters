#include "GameComponents.h"


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
Players& GameComponents::getPlayers() {
    return _players;
}

const Players& GameComponents::getPlayers() const {
    return _players;
}

const DraftBoard* GameComponents::getDraftBoard() const {
    return &_draftBoard;
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

        case PLAY_AGAIN_ST:
            handlePlayAgain(event);
            break;

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

    if(event.eventType == EventType::DRAFT_SELECTION) {
        if(event.data1 == "ww") {
            _players.getPlayer(0).draft( _draftBoard.at(0) );
            _players.getPlayer(1).draft( _draftBoard.at(1) );
            setState(NULL_ST);
        }
    }

}


void GameComponents::handleBattle(const Event& event) {

    std::cout << "GameComponents::handleBattle" << "\n";
    // TODO: handle BATTLE_ST events
    // keep battling until one of the players has no monsters left
    _players.addEventHandler(event);

    if(event.eventType == EventType::ATTACK) {
        if(event.data1 == "qq") {
            setState(NULL_ST);
        }
    }

    if(_players.getState() != GameState::BATTLE_ST) {
        setState(NULL_ST);
    }

}

void GameComponents::handlePlayAgain(const Event& event) {

    // TODO: handle PLAY_AGAIN_ST events
    _players.reset();    
    
    if(event.eventType == EventType::ATTACK) {
        if(event.data1 == "qq") {
            setState(NULL_ST);
        }
    }

}