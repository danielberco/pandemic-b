#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Medic.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

Medic &Medic::treat(City city)
{
    if (_city != city)
    {
        throw invalid_argument{"Illegal action! Medic is not in city: " + city_to_string(city)};
    }

    if (_board[city] == 0)
    {
        throw invalid_argument{"Illegal action! " + city_to_string(_city)};
    }

    _board[city] = 0;
    return *this;
}

void Medic::medic_arrive()
{
    if (_board.cure_discoverd(_city))
    {
        _board[_city] = 0;
    }
}
