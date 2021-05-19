#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{

class Scientist: public Player {
  private:
    int n; 

  public:
  
    Scientist(Board board, City city , int n):Player(board, city),n(n){ }
    Player& discover_cure(Color color_dis) override;
     std::string role() const override{
        return "Scientist";
    }
 };

}