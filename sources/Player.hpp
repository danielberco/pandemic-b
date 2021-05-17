#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>

namespace pandemic
{
class Player {

protected:
    std::string playerRole;
    std::set<City> cards;
    Board& board;
    City city;

public:
    Player(Board& _board,City _city) : board(_board),city(_city) {}

    Player& drive(City c);

    virtual Player& fly_direct(City c);

    Player& fly_charter(City c);

    Player& fly_shuttle(City c);

    virtual Player& build();

    virtual Player& discover_cure(Color c);
    
    virtual Player& treat(City city);

    std::string role(){return playerRole;}

    Player& take_card(City city);

    virtual void arrive(){};
};


}