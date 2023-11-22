#include "Helper.h"

void Helper::logState(States statesObject, 
                      std::string objectName)
{
    std::cout << "Helper::logStates\n";
    std::cout << "\tobject: " << objectName << "\n";
    // std::cout << "\t\tstate: ";
    if(statesObject.checkState(ACTIVE)) {std::cout << "\t\tACTIVE\n";}
    if(statesObject.checkState(RUNNING)) {std::cout << "\t\tRUNNING\n";}
    if(statesObject.checkState(START_UP)) {std::cout << "\t\tSTART_UP\n";}
    if(statesObject.checkState(INIT)) {std::cout << "\t\tINIT\n";}
    if(statesObject.checkState(DRAFT)) {std::cout << "\t\tDRAFT\n";}
    if(statesObject.checkState(ATTACKING)) {std::cout << "\t\tATTACKING\n";}
    if(statesObject.checkState(DEFENDING)) {std::cout << "\t\tDEFENDING\n";}
    if(statesObject.checkState(BATTLE)) {std::cout << "\t\tBATTLE\n";}
    if(statesObject.checkState(BATTLE_OVER)) {std::cout << "\t\tBATTLE_OVER\n";}
    if(statesObject.checkState(REPLAY)) {std::cout << "\t\tREPLAY\n";}
    std::cout << '\n';

}


void Helper::logEvent(Event event, 
                      std::string callLocation)
{
    std::cout << "Helper::logEvent\n";
    std::cout << "\tcall location: " << callLocation << "\n";
    std::cout << "\t\teventType: " << event.eventType << "\n";
    std::cout << "\t\tdata1  : " << event.data << "\n";
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