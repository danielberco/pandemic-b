#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color diseaseColor){
     if(!board.is_station(city)) {
         throw std::invalid_argument {"The city dont have reaserch station!"};
     }
     if (cards.size()<5) {
         throw std::invalid_argument {"You dont have enough cards!"};
     }
     int i=1;
     for (auto it = cards.begin(); it != cards.end();i++) {
         if (i == 5) {
             break;
         }
         it = cards.erase(it);
     }
     board.mark_cure(diseaseColor);
     return *this;
 }
