#pragma once
class Transport{ // should be an interface but there are no interfaces in C++

  public:
    virtual float deliver(float distance) const  = 0; 
};
