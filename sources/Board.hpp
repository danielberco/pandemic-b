#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>


namespace pandemic
{
class Board { 
    static std::map<City,std::set<City>> connect;
    std::map<City,int> cube;
    std::set<Color> colorCure;
    std::set<City> station;

public :
  Board(){} //constructor
  int &operator[] (City c);
  friend std::ostream& operator<<(std::ostream& output, const Board& board);
  bool is_clean();
  void remove_cures();
  static Color color_of(City c);
  bool cure_discoverd (City c);
  static bool is_connect(City& c1, City& c2);
  void build_station(City c);
  bool is_station(City c);
  void mark_cure(Color color);
};
  }