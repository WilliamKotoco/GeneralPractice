#include <iostream>
#include "Transport.hpp"

class Airplane : public Transport{
  public:
    const float velocity = 200;

    float deliver(float distance) const override{
      return distance/this->velocity;
    }
};
