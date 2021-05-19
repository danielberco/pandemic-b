#include <algorithm>
#include <iostream>
#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;



int &Board::operator[](City city)
{
    return cube[city];
}


Board::Board() 
{
    for (int c = (int)City::Algiers; c <= (int)City::Washington; c++)
    {
        cube[(City)c] = 0;
    }
    colorCure.clear();
    station.clear();
}



ostream &pandemic::operator<<(ostream &os, const Board &board)
{
    os << "-------------------------- BOARD --------------------------" << endl;

   
    os << "Level of disease:" << endl;
    for (const auto &pair : board.cube)
    {
        os << "\tCity:" << city_to_string(pair.first) << ", \t\tDisease Cube:" << pair.second << endl;
    }

    
    os << "Cure discovered by colors:" << endl;
    for (const auto &color : board.colorCure)
    {
        os << "\t"
           << "Cure Discovered: "
           << ",\t\t" << color_to_string(color) << endl;
    }

    
    os << "Research stations: " << endl;
    for (const auto &city_rs : board.station)
    {
        os << city_to_string(city_rs) << ", " << endl;
    }

    os << "------------------------- END  -------------------------" << endl;
    return os;
}


bool Board::is_clean() const
{
    for (const auto &city_disease : this->cube)
    {
        if (city_disease.second != 0)
        {
            return false;
        }
    }
    return true;
}


void Board::remove_cures()
{
    colorCure.clear();
}


Color Board::color_of(City city)
{
    return _cities_by_color.at(city);
}

bool Board::cure_discoverd(City city)
{
    return (cure_discoverd(color_of(city)));
}

bool Board::cure_discoverd(Color color)
{
    return (colorCure.count(color) == 1);
}

bool Board::is_connect(const City &city1, const City &city2)
{
    return (connect.at(city1).count(city2) == 1);
}

bool Board::is_station(City city)
{
    return (station.count(city) != 0);
}

void Board::build_station(City city)
{
    station.insert(city);
}

int Board::disease_level(City city)
{
    return (cube.at(city));
}

void Board::mark_as_cure(Color color)
{
    colorCure.insert(color);
}

map<City, set<City>> Board::connect{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};
