#include "Game.h"
#include "GetMonsterList.h"

int main() {

    Game game;
    Timer timer;

    // start game with initial conditions/state
    game.init();

    Monster std::vector<Monster *> monsterList = getMonsterList();

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
    delete[] monsterList;
    return 0;

}