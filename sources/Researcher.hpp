#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{
class Researcher: public Player {
  public:
    Researcher(Board board, City city):Player(board, city){}
    Player& discover_cure(Color color) override;
     std::string role() const override{
        return "Researcher";
    }
 };
}