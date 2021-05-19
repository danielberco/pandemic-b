#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;


Player& Dispatcher::fly_direct(City c){
    if (city==c ) {
        throw std::invalid_argument {"You cannot fly to the same city" + cityStr(c)};
    }
    if(board.is_station(city)) {
        city = c;
    }
    else {
        return Player::fly_direct(c);
    }
    return *this;
}


