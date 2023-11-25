#include "Helper.h"

void Helper::logState(std::string objectName, 
                      GameState state)
{
    std::cout << "Helper::logState\n";
    std::cout << "\tobject: " << objectName << "\n";
    // if(state == ACTIVE_ST) {std::cout << "\t\tACTIVE_ST\n";}
    // if(state == RUNNING_ST) {std::cout << "\t\tRUNNING_ST\n";}
    if(state == START_UP_ST) {std::cout << "\t\tSTART_UP_ST\n";}
    if(state == PLAYERS_SETUP_ST) {std::cout << "\t\tPLAYERS_SETUP_ST\n";}
    if(state == DRAFT_ST) {std::cout << "\t\tDRAFT_ST\n";}
    // if(state == ATTACKING_ST) {std::cout << "\t\tATTACKING_ST\n";}
    // if(state == DEFENDING_ST) {std::cout << "\t\tDEFENDING_ST\n";}
    if(state == BATTLE_ST) {std::cout << "\t\tBATTLE_ST\n";}
    if(state == BATTLE_OVER_ST) {std::cout << "\t\tBATTLE_OVER_ST\n";}
    if(state == PLAY_AGAIN_ST) {std::cout << "\t\tPLAY_AGAIN_ST\n";}
    if(state == QUIT_ST) {std::cout << "\t\tQUIT_ST\n";}
    std::cout << '\n';

}

// void Helper::logState(States statesObject, 
//                       std::string objectName)
// {
//     std::cout << "Helper::logStates\n";
//     std::cout << "\tobject: " << objectName << "\n";
//     // std::cout << "\t\tstate: ";
//     if(statesObject.checkState(ACTIVE)) {std::cout << "\t\tACTIVE\n";}
//     if(statesObject.checkState(RUNNING)) {std::cout << "\t\tRUNNING\n";}
//     if(statesObject.checkState(START_UP)) {std::cout << "\t\tSTART_UP\n";}
//     if(statesObject.checkState(PLAYERS_SETUP)) {std::cout << "\t\tPLAYERS_SETUP\n";}
//     if(statesObject.checkState(DRAFT)) {std::cout << "\t\tDRAFT\n";}
//     if(statesObject.checkState(ATTACKING)) {std::cout << "\t\tATTACKING\n";}
//     if(statesObject.checkState(DEFENDING)) {std::cout << "\t\tDEFENDING\n";}
//     if(statesObject.checkState(BATTLE)) {std::cout << "\t\tBATTLE\n";}
//     if(statesObject.checkState(BATTLE_OVER)) {std::cout << "\t\tBATTLE_OVER\n";}
//     if(statesObject.checkState(PLAY_AGAIN)) {std::cout << "\t\tPLAY_AGAIN\n";}
//     std::cout << '\n';

// }

void Helper::logEvent(Event event, 
                      std::string callLocation)
{
    std::cout << "Helper::logEvent\n";
    std::cout << "\tcall location: " << callLocation << "\n";
    std::cout << "\t\teventType: " << event.eventType << "\n";
    std::cout << "\t\tdata1  : " << event.data1 << "\n";
    std::cout << "\t\tdata2  : " << event.data2 << "\n";
    std::cout << '\n';

}


// void Helper::logEvent(Event event, 
//                       std::string objectName)
// {
//     std::cout << objectName << "  |  logEvent  |  ";
//     if(statesObject.checkState(ACTIVE)) {std::cout << "ACTIVE ";}
//     if(statesObject.checkState(RUNNING)) {std::cout << "RUNNING ";}
//     if(statesObject.checkState(ATTACKING)) {std::cout << "ATTACKING ";}
//     if(statesObject.checkState(BATTLE)) {std::cout << "BATTLE ";}
//     if(statesObject.checkState(BATTLE_OVER)) {std::cout << "BATTLE_OVER ";}
//     std::cout << '\n';

// }