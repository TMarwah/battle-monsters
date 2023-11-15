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
void Game::Init() {
    // Init function implementation
    enableState(ACTIVE);
}

void Game::Update() {
    updateStates();
}

void Game::Draw() {
    // visual functions update required
}

void Game::GetInput() {
    // player class implementation required
}

// Accessors
Player* Game::getPlayers() const{
    return _players;
}


