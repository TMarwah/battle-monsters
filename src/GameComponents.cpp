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

        if(isValidDraftInput(event.data1, event.data2)) {
            unsigned player1SelectIndex = 0;
            if (event.data1 == "1") {
                player1SelectIndex = 0;
            }   else if (event.data1 == "2") {
                player1SelectIndex = 1;
            }   else if (event.data1 == "3") {
                player1SelectIndex = 2;
            }   else if (event.data1 == "4") {
                player1SelectIndex = 3;
            }   else {
                // TODO: throw my computer
            }
            _players.getPlayer(0).draft( _draftBoard.at(player1SelectIndex) );

            unsigned player2SelectIndex = 0;
            if (event.data2 == "1") {
                player2SelectIndex = 0;
            }   else if (event.data2 == "2") {
                player2SelectIndex = 1;
            }   else if (event.data2 == "3") {
                player2SelectIndex = 2;
            }   else if (event.data2 == "4") {
                player2SelectIndex = 3;
            }   else {
                // TODO: throw my computer
            }
            _players.getPlayer(1).draft( _draftBoard.at(player2SelectIndex) );
            setState(NULL_ST);
        }
    }

}


void GameComponents::handleBattle(const Event& event) {

    if(FLAG_ON) {
        std::cout << "GameComponents::handleBattle" << "\n";
    }

    // TODO: handle BATTLE_ST events
    // keep battling until one of the players has no monsters left
    if(isValidBattleInput(event.data1, event.data2)) {
        _players.addEventHandler(event);
    }   
    // else {
    //     // set up the invalid input flag
    //     _players.setState(INVALID_INPUT_ST);
    //     return;
    // }

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

bool GameComponents::isValidDraftInput(const std::string& input1, const std::string& input2) const {
    bool input1Validity = input1 == "1" || input1 == "2" || input1 == "3" || input1 == "4";
    bool inpu21Validity = input2 == "1" || input2 == "2" || input2 == "3" || input2 == "4";

    bool noCoincidence = input1 != input2;

    if(FLAG_ON) {
        std::cout << input1Validity << ", " << inpu21Validity << ", " << noCoincidence << "\n";
    }

    return ( input1Validity && inpu21Validity && noCoincidence );
}

bool GameComponents::isValidBattleInput(const std::string& input1, const std::string& input2) const {
    bool input1Validity = input1 == "1" || input1 == "2";
    bool inpu21Validity = input2 == "1" || input2 == "2";

    if(FLAG_ON) {
        std::cout << input1Validity << ", " << inpu21Validity << "\n";
    }

    return ( input1Validity && inpu21Validity );
}
