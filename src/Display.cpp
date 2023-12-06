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
    std::cout << "=========" << std::endl;
    std::cout << "= DRAFT =" << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "\tp1: " << p1_name << '\n';
    std::cout << "\tp2: " << p2_name << '\n' << '\n';
    // TODO: display player benches
    // TODO: display draft bench
    std::cout << "DRAFTBOARD: \n";
    // for(unsigned i = 0; i < BENCH_SIZE * 2; i++) {
    //     std::cout << draftBoard[i].getName() << "\t|\t";
    // }
    for(unsigned i = 0; i < draftBoard->size(); i++) {
        std::cout << "\tname: " << draftBoard->at(i).getName() << '\n';
        std::cout << "\thealth: " << draftBoard->at(i).getHP() << "\n";
        std::cout << "\tskill set:\n";
        std::cout << "\t  type: Normal" << "\n";
        for(unsigned j = 0; j < draftBoard->at(i).getMoves().size(); ++j) {
            MoveSet* currentMove = draftBoard->at(i).getMoves().at(j);
            const std::string name = (currentMove->getName());
            std::cout << "\t  " << name << ": Damage( \033[1;31m" << (currentMove->getDamage()) << "\033[0m ), Accuracy( "<< (currentMove->getAccuracy() * 100 )<< "% )\n";
        }
        std::cout << '\n';
    }
    std::cout << '\n';

}


void Display::renderBattle(const std::string& p1_name,
                           const std::string& p2_name,
                           const Bench* p1_bench,
                           const Bench* p2_bench) const {
    std::cout << "==========" << '\n';
    std::cout << "= BATTLE =" << '\n';
    std::cout << "==========" << '\n' << '\n';

    // p1 display
    std::cout << "p1: " << p1_name << '\n';
    std::cout << "\t" << p1_bench->getCurrent().getName() << '\n';
    std::cout << "\t" << p1_bench->getCurrent().getHP() << '\n';
    for(unsigned i = 0; i < p1_bench->getCurrent().getMoves().size(); ++i) {
        MoveSet* currentMove = p1_bench->getCurrent().getMoves().at(i);
        std::cout << "\t" << i+1 << ": [" << currentMove->getName() << "] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    // p2 display
    std::cout << '\n';
    std::cout << "p2: " << p2_name << '\n';
    std::cout << "\t" << p2_bench->getCurrent().getName() << '\n';
    std::cout << "\t" << p2_bench->getCurrent().getHP() << '\n';
    for(unsigned i = 0; i < p2_bench->getCurrent().getMoves().size(); ++i) {
        MoveSet* currentMove = p2_bench->getCurrent().getMoves().at(i);
        std::cout << "\t" << i+1 << ": [" << currentMove->getName() << "] Damage( \033[1;31m" << currentMove->getDamage() << "\033[0m ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

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

