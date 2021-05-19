#include "Board.hpp"
using namespace std;
using namespace pandemic;

int& Board::operator[](City _city) {
    return cube[_city];
}

bool Board::is_clean() {
    for(auto& dis: cube) {
        if(dis.second > 0 ) {
            return false;
        }
    }
    return true;
}

void Board::remove_cures() {
    colorCure.clear();
}

Color Board::color_of(City _city) {
    return cityDise.at(_city);
}

void Board::build_station(City _city) {
    station.insert(_city);
}

bool Board::is_station(City _city) {
    return station.contains(_city);
}

void Board::mark_cure(Color _color) {
    colorCure.insert(_color);
}

bool Board::cure_discoverd(City _city) {
    return (bool)colorCure.count(color_of(_city));
}

bool Board::is_connect(City& c1, City& c2) {
    return connect.at(c1).contains(c2);
}



std::ostream& pandemic::operator<<(std::ostream& _output, const Board& board) {
    _output << "---------------Board--------------" << endl;
    _output << "Level Of Disease : " << endl;
    for (const auto& b : board.cube) {
        _output << "/tCity:" << cityStr(b.first) <<  ", \t\tDisease Cube:" << b.second << endl;
    }

    _output << "Cure Discoverd by Colors : " << endl;

    for (const auto &color : board.colorCure)
    {
        _output << "\t"
           << "Cure Discovered: "
           << ",\t\t" << sort_city(color) << endl;
    }

    _output << "Research Stations: " << endl;
     for (const auto &search : board.station)
    {
        _output <<  "\t" << cityStr(search) << endl;
    }

        _output << "------------------------- End Board -------------------------" << endl;
        return _output;
}







std::map<City, std::set<City>> Board::connect {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};