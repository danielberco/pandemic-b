#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "FieldDoctor.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

FieldDoctor &FieldDoctor::treat(City city)
{
    if (Board::is_connect(_city, city) || (_city == city))
    {
        if (_board[city] == 0)
        {
            throw invalid_argument{"Illegal action! FieldDoctor , infection level is zero in: " + city_to_string(_city)};
        }

        if (_board.cure_discoverd(city))
        {
            _board[city] = 0;
        }
        else
        {
            _board[city]--;
        }
        return *this;
    }

    throw invalid_argument{"Illegal action!  " + city_to_string(_city)};
}
