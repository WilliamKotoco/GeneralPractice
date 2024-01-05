
#include "DeliverAirplane.hpp"
#include "DeliverCar.hpp"
#include <string>


int main (int argc, char *argv[]) {
  std::string tipo = "Aviao";
  Deliver *deliver;

  if (tipo == "Carro")
  {
    deliver = new DeliverCar(100, "celta");
  }
  else {
    deliver = new DeliverAirplane(100, "tam");
  }
  

  deliver->infoDeliver();
  return 0;

}

