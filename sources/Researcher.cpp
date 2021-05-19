#include "Researcher.hpp"
using namespace std;
using namespace pandemic;


Player& Researcher::discover_cure(Color color){
    int i=0;
    for(const auto& j : cards) {
        if(Board::color_of(j) == color) {
            i++;
        }
    }

    if(i< 5) {
        throw std::invalid_argument {"Not enough cards!"};
    }
    
    i=1;

    for(auto it = cards.begin();it!=cards.end();i++) {
        if(i == 5) {
            break;
        }
        if(Board::color_of(*it) == color) {
            it= cards.erase(it);
        }
        else {
            ++it;
        }
    }

    board.mark_cure(color);
    return *this;
    
}
