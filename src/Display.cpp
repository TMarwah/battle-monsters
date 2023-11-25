#include "Display.h"


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
void Display::render(const GameComponents& gameComponents) {

    if(CLEAR_SCREEN) {
        system("clear");
    }


    // extract game data and pass to private helpers
    std::string p1_name = gameComponents.getPlayers().getPlayer(0).getName();
    std::string p2_name = gameComponents.getPlayers().getPlayer(1).getName();
    // TODO: extract bench data
    // TODO: extract draft bench data

    // display based off of current game state
    switch(getState())
    {
        case START_UP_ST:
            renderStartup();
            break;

        case PLAYERS_SETUP_ST:
            renderPlayersSetup();
            break;

        case DRAFT_ST:
            renderDraft(p1_name, p2_name);
            break;

        case BATTLE_ST:
            renderBattle();
            break;

        case BATTLE_OVER_ST:
            renderBattleOver();
            break;

        case PLAY_AGAIN_ST:
            renderPlayAgain();
            break;

        case QUIT_ST:
            renderQuit();
            break;
    }

}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
void Display::renderStartup() {
    std::cout << "============" << '\n';
    std::cout << "= START_UP =" << '\n';
    std::cout << "============" << '\n' << '\n';

    // show title screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}


void Display::renderPlayersSetup() const {
    std::cout << "=================" << '\n';
    std::cout << "= PLAYERS_SETUP =" << '\n';
    std::cout << "=================" << '\n' << '\n';

}


void Display::renderDraft(const std::string& p1_name,
                          const std::string& p2_name) const 
{
    std::cout << "=========" << std::endl;
    std::cout << "= DRAFT =" << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "\tp1: " << p1_name << '\n';
    std::cout << "\tp2: " << p2_name << '\n' << '\n';
    // TODO: display player benches
    // TODO: display draft bench

}


void Display::renderBattle() const {
    std::cout << "==========" << '\n';
    std::cout << "= BATTLE =" << '\n';
    std::cout << "==========" << '\n' << '\n';

}


void Display::renderBattleOver() {
    std::cout << "===============" << '\n';
    std::cout << "= BATTLE_OVER =" << '\n';
    std::cout << "===============" << '\n' << '\n';

    // show title screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}


void Display::renderPlayAgain() const {
    std::cout << "===============" << '\n';
    std::cout << "= PLAY AGAIN? =" << '\n';
    std::cout << "===============" << '\n' << '\n';

}


void Display::renderQuit() {
    std::cout << "========" << '\n';
    std::cout << "= QUIT =" << '\n';
    std::cout << "========" << '\n' << '\n';
    
    // show exit screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}

