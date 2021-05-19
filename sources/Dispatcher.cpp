#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(City city)
{
    if (_city == city)
    {
        throw invalid_argument{"Illegal action! Dispatcher alraedy in city: " + city_to_string(city)};
    }

    if (_board.is_station(_city))
    {
        _city = city;
        return *this;
    }

    if (_cards.count(city) == 1)
    {
        _cards.erase(city);
        _city = city;
        return *this;
    }

    throw invalid_argument{"Illegal action! Dispatcher try to fly direct from: " + city_to_string(_city) + " to: " + city_to_string(city)};
}
