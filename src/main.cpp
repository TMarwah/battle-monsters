#include "Game.h"
#include "Input.h"
#include "Event.h"
#include <chrono>
#include <thread>
#include "Timer.h"

int main() {

    Game game;
    Input input;

    Timer timer;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "main time: " << timer.elapsed() << std::endl;

    timer.mark();

    game.init();


    while(game.isRunning())
    {
        // Event event;

        // while(input.pollEvent(event))
        // {
        //     event.logEvent("main.cpp");
        //     game.addEventHandler(event);

        // }

        game.getInput();
        
        game.handleEvents();


        // update
        game.update();

        // draw updated display
        game.render();

        // TODO: possilbly add sleep function here for timing (60 fps?)
        std::cout << "timer: " << timer.elapsed() << std::endl;


    }

    std::cout << "Goodbye" << std::endl;
    return 0;

}