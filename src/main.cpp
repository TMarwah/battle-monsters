#include "Game.h"

#ifndef MONSTER_IMPLEMENTED
    #include "Monster.h"
    #include "GetMonsterList.h"
#endif

int main() {

    Game game;
    Timer timer;

    // start game with initial conditions/state
    game.init();

    if(MONSTER_IMPLEMENTED) {
        // FIXME: uncomment this after implementing Monster class
        // Monster std::vector<Monster *> monsterList = getMonsterList();
    }

    // main game loop
    while(game.isRunning())
    {
        // input: get input from users
        game.getInput();
        
        game.handleEvents();

        // processing: update game after last input event

        // output: render updated display
        game.render();

        // TODO: possilbly add sleep function here for timing (60 fps?)
        std::cout << "time since program launch: " << timer.elapsed() << std::endl;

    }

    std::cout << "Goodbye" << std::endl;

    if(MONSTER_IMPLEMENTED) {
        // FIXME: uncomment this after implementing Monster class
        // delete[] monsterList;
    }
    
    return 0;

}