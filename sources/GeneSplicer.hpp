#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{

class GeneSplicer: public Player {
  public:
    GeneSplicer(Board board, City city):Player(board, city){}
    Player& discover_cure(Color c) override;
     std::string role() const override{
        return "GeneSplicer";
    }
 };

}