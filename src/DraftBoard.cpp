#include "DraftBoard.h"


/*******************************************************************************
* CONSTRUCTOR & DESTRUCTOR
*******************************************************************************/
DraftBoard::DraftBoard() {

    // std::cout << "DraftBoard::DraftBoard" << '\n';

    /*
    std::string str = "";

    for(unsigned i = 0; i < BENCH_SIZE * 2; i++) {
        str = "monster_" + std::to_string(i);
        _draftBoard.push_back(str);
    }
    */

    _draftBoard = new Monster[BENCH_SIZE * 2];

    _draftBoard[0] = Monster("Andrewsaurus", NORMAL, 50, 70);
    _draftBoard[1] = Monster("Willzilla", NORMAL, 60, 60);

    // 120 as a balance factor of stats = attack + defense
    // Monster* Andrewsaurus = new Monster("Andrewsaurus");
    std::vector<MoveSet *> AndrewsaurusMoveset;
    // MoveSets("name", accuracy, base_damage, priority(0 as default));
    AndrewsaurusMoveset.push_back(new NormalAttack("Rock-bottom", 0.9, 25, 1));
    AndrewsaurusMoveset.push_back(new NormalAttack("Charge", 0.4, 50, 0));
    _draftBoard[0].addMoves(AndrewsaurusMoveset);

    std::vector<MoveSet *> WillzillaMoveSet;
    WillzillaMoveSet.push_back(new NormalAttack("Lazer Breath", 0.75, 35, 0));
    WillzillaMoveSet.push_back(new NormalAttack("Stomp", 1, 28, 0));
    _draftBoard[1].addMoves(WillzillaMoveSet);
    

}

DraftBoard::~DraftBoard() {

    // TODO: deallocate memory
    // for(unsigned i = 0; i < _draftBoard.size(); i++) {
    //     std::cout << "~DraftBoard " << _draftBoard.at(i)->getName() << '\n';
    //     delete _draftBoard.at(i);
    // }
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
    return BENCH_SIZE * 2;
}


/*******************************************************************************
* PRIVATE HELPERS
*******************************************************************************/
