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
    DraftBoard* draftBoard = gameComponents.getDraftBoard();

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
    std::cout << "|==============================================================|\n";
    std::cout << "|                                                              |\n";
    std::cout << "|                        " << green("Battle Monsters") << "                       |\n";
    std::cout << "|                                                              |\n";
    std::cout << "|==============================================================|\n";
    std::cout << "\n\n\n";

    // show title screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}


void Display::renderPlayersSetup() const {
    std::cout << "====================================================" << std::endl;
    std::cout << "=                  PLAYERS_SETUP                   =" << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;

}


void Display::renderDraft(const std::string& p1_name,
                          const std::string& p2_name,
                          DraftBoard* draftBoard) 
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
        std::cout << "\thealth: [ " << green(draftBoard->at(i).getHP()) << " / 100 ] \n";
        std::cout << "\t  type: ";
        
        switch (draftBoard->at(i).getType())
        {
        case MonsterType::NORMAL:
            std::cout << "NORMAL";
            break;

        case MonsterType::FIRE:
            std::cout << red("FIRE");
            break;

        case MonsterType::WATER:
            std::cout << blue("WATER");
            break;

        case MonsterType::EARTH:
            std::cout << green("EARTH");
            break;

        case MonsterType::AIR:
            std::cout << white("AIR");
            break;
        
        default:
            std::cout << red_underline(" TYPE: ERROR ");
            break;
        }
        
        std::cout << "  |  power: " << draftBoard->at(i).getPower() << "  |  defense: " << draftBoard->at(i).getDefense() << "\n";
        for(unsigned j = 0; j < draftBoard->at(i).getMoves().size(); ++j) {
            MoveSet* currentMove = draftBoard->at(i).getMoves().at(j);
            const std::string name = (currentMove->getName());
            std::cout << "\t  [ " << cyan(name) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< (currentMove->getAccuracy() * 100 )<< "% )\n";
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // if invalid input
    if(draftBoard->getState() == GameState::NULL_ST) {
        std::cout << red("\t[ INVALID INPUT ] MUST SELECT DIFFERENT MONSTERS (1-4)") << '\n';
        draftBoard->setState(DRAFT_ST);
    }

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
    std::cout << "\t" << white(p1_monster.getName()) << " [ ";

    switch (p1_monster.getType()) {
        case MonsterType::NORMAL:
            std::cout << "NORMAL";
            break;

        case MonsterType::FIRE:
            std::cout << red("FIRE");
            break;

        case MonsterType::WATER:
            std::cout << blue("WATER");
            break;

        case MonsterType::EARTH:
            std::cout << green("EARTH");
            break;

        case MonsterType::AIR:
            std::cout << white("AIR");
            break;
        
        default:
            std::cout << red_underline(" TYPE: ERROR ");
            break;
    }
    std::cout << " ]\n";
    
    std::cout << "\t[ " << green(p1_monster.getHP()) << " / 100 ]\n";
    for(unsigned i = 0; i < p1_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p1_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ " << cyan(currentMove->getName()) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    // p2 display
    std::cout << '\n';
    std::cout << "p2: " << magenta(p2_name) << "\n";
    std::cout << "\t" << white(p2_monster.getName()) << " [ ";

    switch (p2_monster.getType()) {
        case MonsterType::NORMAL:
            std::cout << "NORMAL";
            break;

        case MonsterType::FIRE:
            std::cout << red("FIRE");
            break;

        case MonsterType::WATER:
            std::cout << blue("WATER");
            break;

        case MonsterType::EARTH:
            std::cout << green("EARTH");
            break;

        case MonsterType::AIR:
            std::cout << white("AIR");
            break;
        
        default:
            std::cout << red_underline(" TYPE: ERROR ");
            break;
    }
    std::cout << " ]\n";

    std::cout << "\t[ " << green(p2_monster.getHP()) << " / 100 ]\n";
    for(unsigned i = 0; i < p2_monster.getMoves().size(); ++i) {
        MoveSet* currentMove = p2_monster.getMoves().at(i);
        std::cout << "\t" << i+1 << ": [ " << cyan(currentMove->getName()) << " ] Damage( " << red(currentMove->getDamage()) << " ), Accuracy( "<< currentMove->getAccuracy() * 100 << "% )\n";
    }

    if(p1_monster.getState() == GameState::BATTLE_ST && p2_monster.getState() == GameState::BATTLE_ST) {
        std::cout << "\n\n\n";
        // previous situation display
        std::cout << white(p1_monster.getName()) << " used " << cyan(p1_monster.getMove()->getName());
        if(p1_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> " << red(p2_monster.getLostHealth());

            // check if the attack was effective
            if(getCompatibility(p1_monster.getType(), p2_monster.getType()) == 1.25) {
                std::cout << green(" EFFECTIVE");
            } 
            else if (getCompatibility(p1_monster.getType(), p2_monster.getType()) == 0.75) {
                std::cout << magenta(" NOT EFFECTIVE");
            } 

            std::cout << " damage to " << white(p2_monster.getName()) << "\n";
        }

        std::cout << white(p2_monster.getName()) << " used " << cyan(p2_monster.getMove()->getName());
        if(p2_monster.isMissed()) {
            std::cout << "\n\t>> Attack Missed!\n\n";
        }   else {
            std::cout << "\n\t>> " << red(p1_monster.getLostHealth());

            // check if the attack was effective
            if(getCompatibility(p2_monster.getType(), p1_monster.getType()) == 1.25) {
                std::cout << green(" EFFECTIVE");
            } 
            else if (getCompatibility(p2_monster.getType(), p1_monster.getType()) == 0.75) {
                std::cout << magenta(" NOT EFFECTIVE");
            } 

            std::cout << " damage to " << white(p1_monster.getName()) << "\n";
        }
    }

    else if(p1_monster.getState() == GameState::NULL_ST || p2_monster.getState() == GameState::NULL_ST) {

        std::cout << "\n\n";
        std::cout << red("\t[ INVALID MOVE ]") << '\n';

        p1_monster.setState(GameState::BATTLE_ST);
        p2_monster.setState(GameState::BATTLE_ST);

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

        // check if the attack was effective
        if(getCompatibility(p1_monster.getType(), p2_monster.getType()) == 1.25) {
            std::cout << green(" EFFECTIVE");
        } 
        else if (getCompatibility(p1_monster.getType(), p2_monster.getType()) == 0.75) {
            std::cout << magenta(" NOT EFFECTIVE");
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

        // check if the attack was effective
        if(getCompatibility(p2_monster.getType(), p1_monster.getType()) == 1.25) {
            std::cout << green(" EFFECTIVE");
        } 
        else if (getCompatibility(p2_monster.getType(), p1_monster.getType()) == 0.75) {
            std::cout << magenta(" NOT EFFECTIVE");
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
    std::cout << "|================================================|\n";
    std::cout << "|                                                |\n";
    std::cout << "|                                                |\n";
    std::cout << "|              Play Again [ Y / N ]              |\n";
    std::cout << "|                                                |\n";
    std::cout << "|                                                |\n";
    std::cout << "|================================================|\n\n";

}


void Display::renderQuit() {
    std::cout << "|================================================|\n";
    std::cout << "|                                                |\n";
    std::cout << "|                                                |\n";
    std::cout << "|              " << white("Thanks for playing :)") << "             |\n";
    std::cout << "|                                                |\n";
    std::cout << "|                  " << blue("Stanley Zhang") << "                 |\n";
    std::cout << "|                   " << cyan("William Kim") << "                  |\n";
    std::cout << "|                  " << magenta("Andrew Tilles") << "                 |\n";
    std::cout << "|                  " << red("Tanmay Marwah") << "                 |\n";
    std::cout << "|                                                |\n";
    std::cout << "|                                                |\n";
    std::cout << "|================================================|\n";
    
    // show exit screen for DISPLAY_UPTIME seconds
    _timer.sleep(DISPLAY_UPTIME);
    setState(NULL_ST);

}
