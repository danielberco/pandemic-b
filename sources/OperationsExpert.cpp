#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

OperationsExpert &OperationsExpert::build()
{
    _board.build_station(_city);
    return *this;
}
