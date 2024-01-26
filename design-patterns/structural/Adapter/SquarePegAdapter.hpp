#include "RoundPeg.hpp"
#include "SquarePeg.hpp"
#include <cmath>
class SquarePegAdapter : public RoundPeg
{
  private:
    SquarePeg *peg;

  public:
    SquarePegAdapter(SquarePeg *peg_) :RoundPeg(), peg(peg_) {}
    /// this is the method that will adapt the square to round using math.
    int getRadius() override {return peg->getWidth() * sqrt(2)/2 ;}

};
