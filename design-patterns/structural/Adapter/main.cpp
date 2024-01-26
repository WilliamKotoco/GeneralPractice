#include "RoundPeg.hpp"
#include "SquarePegAdapter.hpp"
#include "RoundHole.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
  RoundHole *hole = new RoundHole(5);
  RoundPeg *peg = new RoundPeg(5);
  
  std::cout << hole->fits(peg) << "\n";

  SquarePeg *small = new SquarePeg(5);
  SquarePeg *big = new SquarePeg(10);

  /// it won't work because they are incompatible
  // hole->fits(small);
  
  SquarePegAdapter *small_adapter = new SquarePegAdapter(small);
  SquarePegAdapter *big_adapter = new SquarePegAdapter(big);

  std::cout << hole->fits(small_adapter) << "\n";
  std::cout << hole->fits(big_adapter) << "\n";
  return 0;
}
