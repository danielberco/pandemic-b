#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"

namespace pandemic
{

class Dispatcher: public Player {
  public:
    Dispatcher(Board board, City city):Player(board, city){}
    Player& fly_direct(City c) override;
    std::string role() const override{
        return "Dispatcher";
    }
 };
}