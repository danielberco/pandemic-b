#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Player
    {
    private:
        int min = 5;

    protected:
        Board &_board;
        City _city;
        std::set<City> _cards;

    public:
        Player(Board &board, City city) : _board(board), _city(city) {}
        virtual std::string role() const = 0;
        Player &take_card(City c);
        void remove_cards();
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);
        virtual Player &fly_charter(City city);
        virtual Player &fly_shuttle(City city);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        virtual void medic_arrive(){};
        bool checkCards(City city);
        int cardSize();
        std::vector<City> getCard(Color color);
    };
}