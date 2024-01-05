#include "Deliver.hpp"
#include "Airplane.hpp"
#include <string>

class DeliverAirplane : public Deliver{
  public:
    std::string m_type;

    DeliverAirplane(float distance, std::string type) : Deliver(distance), m_type(type){}

    Transport *createTransport() override{
      Airplane *airplane = new Airplane();
      return airplane;
    }
};

