#include "Deliver.hpp"
#include "Car.hpp"
#include <string>

class DeliverCar : public Deliver{
  public:
    std::string m_type;

    DeliverCar(float distance, std::string type) : Deliver(distance), m_type(type){}

    Transport *createTransport() override{
      Car *car = new Car();
      return car;
    }
};

