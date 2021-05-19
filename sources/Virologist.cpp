#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Virologist.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

Virologist &Virologist::treat(City city)
{
    if (_board[city] == 0)
    {
        throw invalid_argument{"Illegal action! , infection level is zero in: " + city_to_string(city)};
    }

    if (checkCards(city) || (_city == city))
    {
        if (_board.cure_discoverd(city))
        {
            _board[city] = 0;
            _cards.erase(city);
        }
        else
        {
            _board[city]--;
            _cards.erase(city);
        }
        return *this;
    }

    throw invalid_argument{"Illegal action! "};
}
