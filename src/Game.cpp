#include "Game.h"
#include "Player.h"

//Constructor
Game::Game() {
    _players = new Player[2];
}

//Destructor
Game::~Game() {
    delete[] _players;
}

//Mutators
void Game::init() {
    // Init function implementation
    enableState(ACTIVE);
}

void Game::update() {
    updateStates();
}

void Game::draw() {
    // visual functions update required
}

void Game::getInput() {
    // player class implementation required
}

// Accessors
Player* Game::getPlayers() const{
    return _players;
}


