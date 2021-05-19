#pragma once

#include <iostream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
    protected:
        static std::map<City, std::set<City>> connect;
        std::map<City, int> cube;
        std::set<Color> colorCure;
        std::set<City> station;
    public:
        Board();

        int &operator[](City city);
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        bool is_clean() const;
        void remove_cures();
        static Color color_of(City city);
        bool cure_discoverd(City city);
        bool cure_discoverd(Color color);
        static bool is_connect(const City &city1, const City &city2);
        bool is_station(City city);
        void build_station(City city);
        int disease_level(City city);
        void mark_as_cure(Color color);
    };
}