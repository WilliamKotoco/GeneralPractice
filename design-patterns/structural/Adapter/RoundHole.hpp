#pragma once
#include "RoundPeg.hpp"
#include <iostream>
class RoundHole {
  private:
    int radius;

  public:
    RoundHole(int radius_): radius(radius_) {};
    int getRadius(){ return radius;}
    bool fits(RoundPeg *peg) {
      std::cout <<"Lets see if the peg with " << peg->getRadius() << "will fit \n";
      return radius >= peg->getRadius(); }

};
