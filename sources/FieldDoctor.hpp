#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{
class FieldDoctor: public Player {
  public:
    FieldDoctor(Board board, City city):Player(board, city){}
    Player& treat(City c) override;
     std::string role() const override{
        return "FieldDoctor";
    }
 };
}