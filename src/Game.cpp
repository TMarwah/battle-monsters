#include "Game.h"
// #include "Player.h"
// #include "Helper.h"
// #include "Event.h"


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Game::init() {
    _isRunning = true;
    setState(START_UP_ST);
    _display.setState(START_UP_ST);
}

void Game::getInput() {
    _input.getInput(_gameComponents);
    
}

void Game::handleEvents() {
    addEventHandler(_input.getEvent());

}


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
bool Game::isRunning() const {
    return _isRunning;

}

void Game::render() {
    _display.render(_gameComponents);

}

const Players& Game::getPlayers() const {
    return _gameComponents.getPlayers();
}

/*******************************************************************************
* VIRTUAL OVERRIDES
*******************************************************************************/
void Game::addEventHandler(const Event& event) {

    // output logs during development
    // Helper::logEvent(event, "Game::addEventHandler");
    // Helper::logState("game", getState());

    // handle member based on state events
    switch(getState()) 
    {

        case START_UP_ST:
            handleStartUp();
            break;

        case PLAYERS_SETUP_ST:
            handlePlayersSetup(event);
            break;

        case DRAFT_ST:
            handleDraft(event);
            break;

        case BATTLE_ST:
            handleBattle(event);
            break;

        case BATTLE_OVER_ST:
            handleBattleOver();
            break;

        case PLAY_AGAIN_ST:
            handlePlayAgain(event);
            break;

        case QUIT_ST:
            handleQuit();
            break;

    }

}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
void Game::setGameState(GameState state) {
    setState(state);
    _input.setState(state);
    _gameComponents.setState(state);
    _display.setState(state);

}

void Game::quit() {
    _isRunning = false;

}

/*******************************************************************************
* PRIVATE HELPERS - HANDLERS
*******************************************************************************/
void Game::handleStartUp() {

    if(_display.getState() != START_UP_ST) {
        // switch states: START_UP_ST ==> PLAYERS_SETUP_ST
        setGameState(PLAYERS_SETUP_ST);
    }

}


void Game::handlePlayersSetup(const Event& event) {

    // pass event to game components
    _gameComponents.addEventHandler(event);

    // test to see if the player setup has completed
    if(_gameComponents.getState() != PLAYERS_SETUP_ST) {
        // switch states: PLAYERS_SETUP_ST ==> DRAFT_ST
        setGameState(DRAFT_ST);
    }

}


void Game::handleDraft(const Event& event) {

    // pass event to game components
    _gameComponents.addEventHandler(event);

    // test to see if the DRAFT_ST has completed
    if(_gameComponents.getState() != DRAFT_ST) {
        
        // switch states: DRAFT_ST ==> BATTLE_ST
        setGameState(BATTLE_ST);

    }

}


void Game::handleBattle(const Event& event) {

    // pass event to game components
    _gameComponents.addEventHandler(event);

    if(_gameComponents.getState() != BATTLE_ST) {
        // switch states: BATTLE_ST ==> BATTLE_OVER_ST
        setGameState(BATTLE_OVER_ST);
    }

}


void Game::handleBattleOver() {

    if(_display.getState() != BATTLE_OVER_ST) {
        // switch states: BATTLE_OVER_ST ==> PLAY_AGAIN_ST
        setGameState(PLAY_AGAIN_ST);
    }

}


void Game::handlePlayAgain(const Event& event) {

    if(event.eventType == EventType::REPLAY) {
        // TODO: reset player benches and DRAFT_ST bench
        setGameState(DRAFT_ST);
    }
    else if(event.eventType == EventType::QUIT) {
        setGameState(QUIT_ST);
    }
    // TODO: should an assert go here?

}


void Game::handleQuit() {

    // quit program after _display has shown exit screen
    if(_display.getState() != QUIT_ST) {
        quit();
    }

}