#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

    Player& FieldDoctor::treat(City c){
        if (!Board::is_connect(city,c) && city != c) {
            throw std::invalid_argument{"No connection" + cityStr(c)};
        }

        if (board[c] == 0) {
            throw std::invalid_argument{"No more cubes" + cityStr(c)};
        }
        else {
            board[c]--;
        }
        return *this;
    }
