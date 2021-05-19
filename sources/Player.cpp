#include <iostream>
#include <vector>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;


Player &Player::take_card(City city)
{
    _cards.insert(city);
    return *this;
}
void Player::remove_cards()
{
    _cards.clear();
}


Player &Player::drive(City city)
{
    if (_city == city)
    {
        throw invalid_argument{"Illegal action! you are alraedy in city: " + city_to_string(city)};
    }
    if (!Board::is_connect(_city, city) && !Board::is_connect(city, _city))
    {
        throw invalid_argument{"Illegal action! this Cities: " + city_to_string(_city) + " and " + city_to_string(city) + ", are not connect."};
    }
    _city = city;
    medic_arrive();
    return *this;
}

Player &Player::fly_direct(City city)
{
    if (_city == city)
    {
        throw invalid_argument{"Illegal action! you are alraedy in city: " + city_to_string(city)};
    }
    if (_cards.count(city) == 0)
    {
        throw invalid_argument{"Illegal action! the player dosen\'t have " + city_to_string(city) + " card."};
    }
    _cards.erase(city);
    _city = city;
    medic_arrive();
    return *this;
}

Player &Player::fly_charter(City city)
{
    if (_city == city)
    {
        throw invalid_argument{"Illegal action! you are alraedy in city: " + city_to_string(city)};
    }
    if (_cards.count(_city) == 0)
    {
        throw invalid_argument{"Illegal action! the player dosen\'t have " + city_to_string(_city) + " card."};
    }
    _cards.erase(_city);
    _city = city;
    medic_arrive();
    return *this;
}

Player &Player::fly_shuttle(City city)
{
    if (_city == city)
    {
        throw invalid_argument{"Illegal action! you are alraedy in city: " + city_to_string(city)};
    }
    if (!_board.is_station(_city) || !_board.is_station(city))
    {
        throw invalid_argument{"Illegal action! the player dosen\'t have " + city_to_string(_city) + " card."};
    }
    _city = city;
    medic_arrive();
    return *this;
}

Player &Player::build()
{
    if (_cards.count(_city) == 0)
    {
        throw invalid_argument{"Illegal action! the player dosen\'t have " + city_to_string(_city) + " card."};
    }
    if (_board.is_station(_city))
    {
        cout << city_to_string(_city) << ", already have a research stations." << endl;
        return *this;
    }
    _cards.erase(_city);
    _board.build_station(_city);
    return *this;
}

Player &Player::discover_cure(Color color)
{
    if (_board.cure_discoverd(color))
    {
        return *this;
    }

    if (_board.is_station(_city))
    {
        vector<City> to_throw = getCard(color);
        if (to_throw.size() >= min)
        {
            for (size_t i = 0; i < min; i++)
            {
                _cards.erase(to_throw.at(i));
            }
            _board.mark_as_cure(color);
        }
        else
        {
            throw invalid_argument{"Illegal action! try to cure where is no 5 cards of: " + color_to_string(color)};
        }
    }
    else
    {
        throw invalid_argument{"Illegal action! try to cure where is no research station in: " + city_to_string(_city)};
    }
    return *this;
}

Player &Player::treat(City city)
{
    if (_board[_city] == 0)
    {
        throw invalid_argument{"Illegal action! infection level is zero in: " + city_to_string(_city)};
    }

    if (_board.cure_discoverd(_city))
    {
        _board[_city] = 0;
    }
    else
    {
        _board[_city]--;
    }
    return *this;
}


bool Player::checkCards(City city)
{
    return (_cards.count(city) == 1);
}

int Player::cardSize()
{
    return _cards.size();
}

vector<City> Player::getCard(Color color)
{
    vector<City> ans;
    for (const auto &card : _cards)
    {
        if (Board::color_of(card) == color)
        {
            ans.push_back(card);
        }
    }
    return ans;
}
