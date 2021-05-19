#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::treat(City c){
   if (city != c) {
     throw std::invalid_argument {"You are not in that city"};
     }
   if(board[c] == 0) {
    throw std::invalid_argument {"You dont have any more cubes"};
    }

    board[c] = 0;
    return *this;
}
void Medic::arrive() {
  if(board.cure_discoverd(city)) {
    board[city] =0;
  }
}

