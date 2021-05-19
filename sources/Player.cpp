#include "Player.hpp"
#include <string>
using namespace std;
using namespace pandemic;

const int cards_taken = 5;

Player& Player::drive(City _city) {
    if (city == _city) {
        throw std::invalid_argument {
            "You cannot drive to the same city" + cityStr(_city)};
    }

    if (!Board::is_connect(city,_city)) {
        throw std::invalid_argument {
            "You chose cities that are not connected" };
    }
    city = _city;
    arrive();
    return *this;
}

Player& Player::fly_direct(City _city) {
    if (city == _city) {
        throw std::invalid_argument {
            "You cannot fly to the same city" + cityStr(_city)};
    }

    if(cards.count(city)==0) {
        throw std::invalid_argument {
            "You don't have the card of" + cityStr(_city)};
    }
    cards.erase(city);
    city = _city;
    arrive();
    return *this;
}

Player& Player::fly_charter(City _city) {
    if (city == _city) {
        throw std::invalid_argument {
            "You cannot fly to the same city" + cityStr(_city)};
    }

    if(cards.count(city)==0) {
        throw std::invalid_argument {
            "You don't have the card of" + cityStr(_city)};
    }
    cards.erase(city);
    city = _city;
    arrive();
    return *this;
}

Player& Player::fly_shuttle(City _city) { 
    if (city == _city) {
        throw std::invalid_argument {
            "You cannot fly to the same city" + cityStr(_city)};
        }
    if (!board.is_station(_city) || !board.is_station(city)) {
        throw std::invalid_argument {
            "The cities don't have research stations"};
    }
    city = _city;
    arrive();
    return *this;
}

Player& Player::build() {
    if(cards.count(city)==0) {
        throw std::invalid_argument {"You must have the " + cityStr(city) + "card" + "to build a station!"};
    }
    board.build_station(city);
    cards.erase(city);
    return *this;
}

Player& Player::discover_cure(Color _color) {
    int count =0;
    if(!board.is_station(city)) {
         throw std::invalid_argument { cityStr(city)+ "do not have research station"};
    }

    for(const auto& t : cards) {
        if(Board::color_of(t) == _color) {
            count++;
        }
    }

    if(count < cards_taken) {
        throw std::invalid_argument {"You only have" + std::to_string(count) + " cards left"};
    }
    count = 1;
    for (auto it = cards.begin(); it != cards.end();count++) {
        if(count == cards_taken) {
            break;
        }

        if (Board::color_of(*it) == _color) {
            it = cards.erase(it);
        }
        else {
            ++it;
        }
    }
    board.mark_cure(_color);
    return *this;
}

Player& Player::treat(City _city) {
    if (city == _city) {
        throw std::invalid_argument {
            "You cannot go to the same city" + cityStr(_city)};
        }
    if (board[_city] == 0) {
                throw std::invalid_argument{"no more cubes in city " + cityStr(_city)};
    }

    if(board.cure_discoverd(_city)) {
        board[_city] = 0;
    }

    else {
        board[_city]--;
    }
    return *this;
}

Player &Player::take_card(City city)
{
    cards.insert(city);
    return *this;
}













