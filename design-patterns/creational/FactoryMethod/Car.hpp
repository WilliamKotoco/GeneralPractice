#include "Transport.hpp"

class Car : public Transport
{
  public:
    const float velocity = 90;

    float deliver(float distance) const override{
      return distance/this->velocity;
    }

};
