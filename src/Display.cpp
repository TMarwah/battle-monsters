#include "Display.h"


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
void Display::render(GameComponents& gameComponents) {

    if(CLEAR_SCREEN) {
        system("clear");
    }


    // extract game data and pass to private helpers
    std::string p1_name = gameComponents.getPlayers().getPlayer(0).getName();
    std::string p2_name = gameComponents.getPlayers().getPlayer(1).getName();
    // TODO: extract bench data
    const Bench* p1_bench = gameComponents.getPlayers().getPlayer(0).getBench();
    const Bench* p2_bench = gameComponents.getPlayers().getPlayer(1).getBench();
    // TODO: extract draft bench data
    const DraftBoard* draftBoard = gameComponents.getDraftBoard();

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
            renderDraft(p1_name, p2_name, draftBoard);
            break;

        case BATTLE_ST:
            renderBattle(p1_name, p2_name, p1_bench, p2_bench);
            break;

        case BATTLE_OVER_ST:
            renderBattleOver(gameComponents);
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
    // std::cout << "=========" << '\n';
    // std::cout << "= START =" << '\n';
    // std::cout << "=========" << '\n' << '\n';
    std::cout << "|===============================|\n";
    std::cout << "|                               |\n";
    std::cout << "|        Battle Monsters        |\n";
    std::cout << "|                               |\n";
    std::cout << "|===============================|\n";
    std::cout << "\n";

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
                          const std::string& p2_name,
                          const DraftBoard* draftBoard) const 
{
    std::cout << "====================================================" << std::endl;
    std::cout << "=                      DRAFT                       =" << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;
    std::cout << "\tp1: " << blue(p1_name) << "\n";
    std::cout << "\tp2: " << magenta(p2_name) << "\n\n";
    // TODO: display player benches
    // TODO: display draft bench
    std::cout << "DRAFTBOARD: \n";
    // for(unsigned i = 0; i < BENCH_SIZE * 2; i++) {
    //     std::cout << draftBoard[i].getName() << "\t|\t";
    // }
    for(unsigned i = 0; i < draftBoard->size(); i++) {
        std::cout << "\t" << ( i + 1 ) << ". " << white(draftBoard->at(i).getName()) << "\n";
        std::cout << "\thealth: " << green(draftBoard->at(i).getHP()) << "\n";
        std::cout << "\t  type: Normal  |  power: " << draftBoard->at(i).getPower() << "  |  defense: " << draftBoard->at(i).getDefense() << "\n";
        for(unsigned j = 0; j < draftBoard->at(i).getMoves().size(); ++j) {
            MoveSet* currentMove = draftBoard->at(i).getMoves().at(j);
            const std::string name = (currentMove->getName());
            std::cout << "\t  [ " << cyan(name) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< (currentMove->getAccuracy() * 100 )<< "% )\n";
        }
        std::cout << '\n';
    }
    std::cout << '\n';

}


void Display::renderBattle(const std::string& p1_name,
                           const std::string& p2_name,
                           const Bench* p1_bench,
                           const Bench* p2_bench) const {
    std::cout << "=====================================================" << std::endl;
    std::cout << "=                      BATTLE                       =" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    Monster& p1_monster = p1_bench->getCurrent();
    Monster& p2_monster = p2_bench->getCurrent();

    // p1 display
    std::cout << "p1: " << blue(p1_name) << "\n";
    std::cout << "\t" << white(p1_monster.getName()) << "\n";
    std::cout << "\t[ " << green(p1_monster.getHP()) << " / 100 ]\n";
    for(unsigned i = 0; i < p1_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p1_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ " << cyan(currentMove->getName()) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    // p2 display
    std::cout << '\n';
    std::cout << "p2: " << magenta(p2_name) << "\n";
    std::cout << "\t" << white(p2_monster.getName()) << "\n";
    std::cout << "\t[ " << green(p2_monster.getHP()) << " / 100 ]\n";
    for(unsigned i = 0; i < p2_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p2_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ " << cyan(currentMove->getName()) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    // TODO: checkes if it is not invalid statement
    /*if(isValidBattleInput()) {
        std::cout << "\n\n" << red("[ INVALID INPUT ] please provide another valid input.");
    }
    // if both monsters are in BATTLE_ST && is not an invalid input
    else */if(p1_monster.getState() == GameState::BATTLE_ST && p2_monster.getState() == GameState::BATTLE_ST) {
        std::cout << "\n\n\n";
        // previous situation display
        std::cout << white(p1_monster.getName()) << " used " << cyan(p1_monster.getMove()->getName());
        if(p1_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> " << red(p2_monster.getLostHealth());
            std::cout << " damage to " << white(p2_monster.getName()) << "\n";
        }

        std::cout << white(p2_monster.getName()) << " used " << cyan(p2_monster.getMove()->getName());
        if(p2_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> " << red(p1_monster.getLostHealth());
            std::cout << " damage to " << white(p1_monster.getName()) << "\n";
        }
    }

}


void Display::renderBattleOver(GameComponents& gameComponents) {
    
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|              Battle Over             |\n";


    bool player1Defeated = gameComponents.getPlayers().getPlayer(0).isDefeated();
    bool player2Defeated = gameComponents.getPlayers().getPlayer(1).isDefeated();
    if(player1Defeated && player2Defeated) {
        std::cout << "|                 " << white("DRAW") << "                 |\n";
    }
    else if(player1Defeated) {
        std::cout << "|           Winner: "<< magenta("Player 2") << "           |\n";
    }   
    else if(player2Defeated) {
        std::cout << "|           Winner: " << blue("Player 1") << "           |\n";
    }


    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";


    // previous situation display for the winner
    Monster& p1_monster = gameComponents.getPlayers().getPlayer(0).getBench()->getCurrent();
    Monster& p2_monster = gameComponents.getPlayers().getPlayer(1).getBench()->getCurrent();
    std::cout << "\n\n\n";
    std::cout << white(p1_monster.getName()) << " used " << cyan(p1_monster.getMove()->getName());
    if(p1_monster.isMissed()) {
        std::cout << "\n\t>> Attack Missed!\n\n";
    }   else {
        std::cout << "\n\t>> " << red(p2_monster.getLostHealth());
        if(p2_monster.isDead()) {
            std::cout << " " << red_underline("FATAL");
        }
        std::cout << " damage to " << white(p2_monster.getName()) << "\n";
    }
    std::cout << white(p2_monster.getName()) << " used " << cyan(p2_monster.getMove()->getName());
    if(p2_monster.isMissed()) {
        std::cout << "\n\t>> Attack Missed!\n\n";
    }   else {
        std::cout << "\n\t>> " << red(p1_monster.getLostHealth());
        if(p1_monster.isDead()) {
            std::cout << " " << red_underline("FATAL");
        }
        std::cout << " damage to " << white(p1_monster.getName()) << "\n";
    }

    // show title screen for ENDING_UPTIME seconds
    _timer.sleep(ENDING_UPTIME);
    setState(NULL_ST);

}


void Display::renderPlayAgain() const {
    // std::cout << "===============" << '\n';
    // std::cout << "= PLAY AGAIN? =" << '\n';
    // std::cout << "===============" << '\n' << '\n';
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|           Play Again (Y/N)           |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";

}


void Display::renderQuit() {
    // std::cout << "========" << '\n';
    // std::cout << "= QUIT =" << '\n';
    // std::cout << "========" << '\n' << '\n';
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|          Thanks for playing :)       |\n";
    std::cout << "|                                      |\n";
    std::cout << "|             Stanley Zhang            |\n";
    std::cout << "|              William Kim             |\n";
    std::cout << "|             Andrew Tilles            |\n";
    std::cout << "|             Tanmay Marwah            |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";
    
    // show exit screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}



// FORMATTING helpers

std::string Display::red(const std::string& message) const {
    std::string formattedMessage = "\033[1;31m" + message + "\033[0m";
    return formattedMessage;
}

std::string Display::red(int message) const {
    std::string formattedMessage = "\033[1;31m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string Display::red(float message) const {
    std::string formattedMessage = "\033[1;31m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string Display::white(const std::string& message) const {
    std::string formattedMessage = "\033[1;37m" + message + "\033[0m";
    return formattedMessage;
}

std::string Display::cyan(const std::string& message) const {
    std::string formattedMessage = "\033[1;36m" + message + "\033[0m";
    return formattedMessage;
}

std::string Display::blue(const std::string& message) const {
    std::string formattedMessage = "\033[1;34m" + message + "\033[0m";
    return formattedMessage;
}
std::string Display::magenta(const std::string& message) const {
    std::string formattedMessage = "\033[1;35m" + message + "\033[0m";
    return formattedMessage;
}

std::string Display::green(int message) const {
    std::string formattedMessage = "\033[1;32m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string Display::red_underline(const std::string& message) const {
    std::string formattedMessage = "\033[1;4;31m" + message + "\033[0m";
    return formattedMessage;
}
