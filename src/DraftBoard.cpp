#include "DraftBoard.h"


/*******************************************************************************
* CONSTRUCTOR & DESTRUCTOR
*******************************************************************************/
DraftBoard::DraftBoard() {

    if(FLAG_ON) {
        std::cout << "DraftBoard::DraftBoard" << '\n';
    }

   // FIXME: later change it to BENCH_SIZE * 2
    _draftBoard = new Monster[BENCH_SIZE * 4];

    _draftBoard[0] = Monster("Andrewsaurus", EARTH, 45, 75);
    _draftBoard[1] = Monster("Willzilla", FIRE, 60, 60);
    _draftBoard[2] = Monster("Tanmystic", AIR, 80, 40);
    _draftBoard[3] = Monster("John Wink", NORMAL, 100, 20);

    // 120 as a balance factor of stats = attack + defense
    // Monster* Andrewsaurus = new Monster("Andrewsaurus");
    std::vector<MoveSet *> AndrewsaurusMoveset;
    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    AndrewsaurusMoveset.push_back(new NormalAttack("Rock-bottom", 0.9, 30, 0));
    AndrewsaurusMoveset.push_back(new NormalAttack("Charge", 0.70, 40, 0));
    _draftBoard[0].addMoves(AndrewsaurusMoveset);

    std::vector<MoveSet *> WillzillaMoveSet;
    WillzillaMoveSet.push_back(new NormalAttack("Stomp", 1, 30, 0));
    WillzillaMoveSet.push_back(new NormalAttack("Lazer Breath", 0.3, 60, 0));
    _draftBoard[1].addMoves(WillzillaMoveSet);

    std::vector<MoveSet *> TanmysticMoveset;
    TanmysticMoveset.push_back(new NormalAttack("Crunch", 0.9, 30, 0));
    TanmysticMoveset.push_back(new NormalAttack("Focus Shot", 0.33, 70, 0));
    _draftBoard[2].addMoves(TanmysticMoveset);

    std::vector<MoveSet *> JohnWinkMoveSet;
    JohnWinkMoveSet.push_back(new NormalAttack("Punch", 0.9, 30, 0));
    JohnWinkMoveSet.push_back(new NormalAttack("Gun", 0.1, 90, 0));
    _draftBoard[3].addMoves(JohnWinkMoveSet);
    
    setState(DRAFT_ST);

}

DraftBoard::~DraftBoard() {

    for(unsigned i = 0; i < BENCH_SIZE * 4; i++) {
        const std::vector<MoveSet* >& copyMoves = _draftBoard[i].getSkillset().getMoves();
        for(unsigned j = 0; j < copyMoves.size(); ++j) {
            if(copyMoves.at(j) != nullptr) {
                delete copyMoves.at(j);
            }
        }
    }
    delete[] _draftBoard;

}

/*******************************************************************************
* MUTATORS
*******************************************************************************/
// void DraftBoard::reset() {

//     for(unsigned i = 0; i < _draftBoard.size(); i++) {
//         _draftBoard.at(i)->setState(UNDRAFTED_ST);
//     }

// }

// Monster* DraftBoard::pick(unsigned index) {

//     assert(index < BENCH_SIZE);

//     // set the pick to DRAFTED_ST
//     _draftBoard.at(index)->setState(NULL_ST);

//     return _draftBoard.at(index);

// }


/*******************************************************************************
* ACCESSORS
*******************************************************************************/
Monster DraftBoard::at(unsigned index) {
    assert(index < size());

    return _draftBoard[index];
}

Monster DraftBoard::at(unsigned index) const {
    assert(index < size());

    return _draftBoard[index];
}

// std::string DraftBoard::at(unsigned index) {
//     return _draftBoard.at(index);
// }

// std::string DraftBoard::at(unsigned index) const {
//     return _draftBoard.at(index);
// }

unsigned DraftBoard::size() const {
    // FIXME: later change it to BENCH_SIZE * 2
    return BENCH_SIZE * 4;
}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
