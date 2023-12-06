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
    std::cout << "\tp1: \033[1;34m" << p1_name << "\033[0m\n";
    std::cout << "\tp2: \033[1;35m" << p2_name << "\033[0m\n\n";
    // TODO: display player benches
    // TODO: display draft bench
    std::cout << "DRAFTBOARD: \n";
    // for(unsigned i = 0; i < BENCH_SIZE * 2; i++) {
    //     std::cout << draftBoard[i].getName() << "\t|\t";
    // }
    for(unsigned i = 0; i < draftBoard->size(); i++) {
        std::cout << "\t" << ( i + 1 ) << ". \033[1;37m" << draftBoard->at(i).getName() << "\033[0m\n";
        std::cout << "\thealth: \033[1;32m" << draftBoard->at(i).getHP() << "\033[0m\n";
        std::cout << "\t  type: Normal  |  power: " << draftBoard->at(i).getPower() << "  |  defense: " << draftBoard->at(i).getDefense() << "\n";
        for(unsigned j = 0; j < draftBoard->at(i).getMoves().size(); ++j) {
            MoveSet* currentMove = draftBoard->at(i).getMoves().at(j);
            const std::string name = (currentMove->getName());
            std::cout << "\t  [ \033[1;36m" << name << "\033[0m ] Damage( \033[1;31m" << (currentMove->getDamage()) << "\033[0m ), Accuracy( "<< (currentMove->getAccuracy() * 100 )<< "% )\n";
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
    std::cout << "p1: \033[1;34m" << p1_name << "\033[0m\n";
    std::cout << "\t\033[1;37m" << p1_monster.getName() << "\033[0m\n";
    std::cout << "\t[ \033[1;32m" << p1_monster.getHP() << "\033[0m / 100 ]\n";
    for(unsigned i = 0; i < p1_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p1_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ \033[1;36m" << currentMove->getName() << "\033[0m ] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    // p2 display
    std::cout << '\n';
    std::cout << "p2: \033[1;35m" << p2_name << "\033[0m\n";
    std::cout << "\t\033[1;37m" << p2_monster.getName() << "\033[0m\n";
    std::cout << "\t[ \033[1;32m" << p2_monster.getHP() << "\033[0m / 100 ]\n";
    for(unsigned i = 0; i < p2_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p2_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ \033[1;36m" << currentMove->getName() << "\033[0m ] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }


    // if both monsters are in BATTLE_ST
    if(p1_monster.getState() == GameState::BATTLE_ST && p2_monster.getState() == GameState::BATTLE_ST) {
        std::cout << "\n\n\n";
        // previous situation display
        std::cout << "\033[1;37m" << p1_monster.getName() << "\033[0m used \033[1;36m" << p1_monster.getMove()->getName() << "\033[0m";
        if(p1_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> \033[1;31m" << p2_monster.getLostHealth() << "\033[0m";
            if(p2_monster.isDead()) {
                std::cout << " fatal";
            }
            std::cout << " damage to \033[1;37m" << p2_monster.getName() << "\033[0m\n";
        }

        std::cout << "\033[1;37m" << p2_monster.getName() << "\033[0m used \033[1;36m" << p2_monster.getMove()->getName() << "\033[0m";
        if(p2_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> \033[1;31m" << p1_monster.getLostHealth() << "\033[0m";
            if(p1_monster.isDead()) {
                std::cout << " fatal";
            }
            std::cout << " damage to \033[1;37m" << p1_monster.getName() << "\033[0m\n";
        }
    }

}


void Display::renderBattleOver(GameComponents& gameComponents) {
    // std::cout << "===============" << '\n';
    // std::cout << "= BATTLE_OVER =" << '\n';
    // std::cout << "===============" << '\n' << '\n';
    std::cout << "|======================================|\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|              Battle Over             |\n";

    if(gameComponents.getPlayers().getPlayer(0).isDefeated() && gameComponents.getPlayers().getPlayer(1).isDefeated()) {
        std::cout << "|                 \033[1;37mDRAW\033[0m                 |\n";
    }
    else if(gameComponents.getPlayers().getPlayer(0).isDefeated()) {
        std::cout << "|           Winner: \033[1;35mPlayer 2\033[0m           |\n";
    }   
    else {
        std::cout << "|           Winner: \033[1;34mPlayer 1\033[0m           |\n";
    }

    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|======================================|\n";

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

