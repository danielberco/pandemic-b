#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player& Virologist::treat(City c){
    if(city != c) {
        cards.erase(c);
    }

    else if(board[c] == 0) {
        throw std::invalid_argument{"No more cubes"};
    }
    else if(board.cure_discoverd(c)) {
        board[c]=0;
        return *this;
    }
    board[c]--;
    return *this;
 }