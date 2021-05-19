#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Researcher &Researcher::discover_cure(Color color)
{
    if (_board.cure_discoverd(color))
    {
        return *this;
    }

    vector<City> to_throw = getCard(color);
    if (to_throw.size() >= min_cards)
    {
        for (size_t i = 0; i < min_cards; i++)
        {
            _cards.erase(to_throw.at(i));
        }
        _board.mark_as_cure(color);
    }
    else
    {
        throw invalid_argument{"Illegal action!" + color_to_string(color)};
    }

    return *this;
}
