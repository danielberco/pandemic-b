#include "Scientist.hpp"
using namespace std;
using namespace pandemic;


Player& Scientist::discover_cure(Color color){
    if (!board.is_station(city)) {
       throw std::invalid_argument {"No staion in this city!"};
    }

    int i=0;
    for(const auto& j : cards) {
        if(Board::color_of(j) == color) {
            i++;
        }
    }
    if(i<n) {
        throw std::invalid_argument {"Not enough cards!"};
    }
    i =1;
     for(auto it = cards.begin();it!=cards.end();i++) {
         if(i == n) {
             break;
         }
         if(Board::color_of(*it) == color) {
             it = cards.erase(it);
         }
     }
     board.mark_cure(color);
     *this;
}
