#pragma once
#include "Transport.hpp"
#include <cstdio> 
class Deliver{

  protected:
    float m_distance;
  public:

    Deliver(float distance) : m_distance(distance){}


    virtual Transport *createTransport() = 0;

    void infoDeliver(){
      Transport *t = createTransport();
      std::printf("Transport of %f will take %f hours ", m_distance, t->deliver(m_distance));
    }


};
