#include "Game.h"
#include "Player.h"
#include "Helper.h"
#include "Event.h"


/*******************************************************************************
* CONSTRUCTOR & DESTRUCTOR
*******************************************************************************/
Game::Game() {
    _players = new Player[2];
}

Game::~Game() {
    delete[] _players;
}


/*******************************************************************************
* MUTATORS
*******************************************************************************/
void Game::init() {
    // Init function implementation
    enableState(RUNNING);
    enableState(START_UP);
    _display.enableState(START_UP);
    // _input.enableState(INIT);
    // enableState(ATTACKING);
    // enableState(BATTLE_OVER);
}

void Game::getInput() {
    _input.getInput();
    
}

void Game::handleEvents() {
    addEventHandler(_input.getEvent());

}

Player* Game::getPlayers() const{
    return _players;
}


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
bool Game::isRunning() const {
    return checkState(RUNNING);

}

void Game::render() const {
    std::cout << _timer.elapsed() << std::endl;
    _display.render(_players[0], _players[1]);

}


/*******************************************************************************
* VIRTUAL OVERRIDES
*******************************************************************************/
void Game::addEventHandler(Event event) {

    // event.logEvent("Game::addEventHandler");
    Helper::logEvent(event, "Game::addEventHandler");
    Helper::logState(*this, "game");

    // handle member events
    // _players.addEventHandler(event);


    // handle Game events
    if(checkState(START_UP))
    {

        // if 3 seconds has passed switch to INIT state
        if(_timer.elapsed() > 1) {
            // disable START_UP states
            disableState(START_UP);
            _display.disableState(START_UP);

            // enable INIT states
            enableState(INIT);
            _display.enableState(INIT);
            _input.enableState(INIT);
            _players[0].enableState(INIT);
            _players[1].enableState(INIT);

        }


        // _input.enableState(INIT);
        // _display.enableState(INIT);
        // _players[0].enableState(INIT);
        // _players[1].enableState(INIT);

    }
    else if(checkState(INIT))
    {
        if(event.eventType == EventType::SET_NAMES) {
            _players[0].addEventHandler(event);
            _players[1].addEventHandler(event);

            disableState(INIT);
            _input.disableState(INIT);
            _display.disableState(INIT);
            _players[0].disableState(INIT);
            _players[1].disableState(INIT);

            enableState(DRAFT);
            _input.enableState(DRAFT);
            _display.enableState(DRAFT);
            
        }

        
    }
    else if(checkState(DRAFT))
    {
        std::cout << "DRAFT STATE" << std::endl;

    }
    else if(checkState(BATTLE))
    {
        std::cout << "BATTLE STATE" << std::endl;

    }
    else if(checkState(REPLAY))
    {
        switch(event.eventType)
        {
            case EventType::A :
                disableState(BATTLE_OVER);
                disableState(RUNNING);
                break;
            case EventType::B:
                disableState(BATTLE_OVER);
                enableState(DRAFT);
                break;
        }
    }

}

void Game::update() {

    _players[0].update();
    _players[1].update();



    updateStates();
}