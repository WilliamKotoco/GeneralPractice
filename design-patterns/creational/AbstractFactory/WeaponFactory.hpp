#include<iostream>
#include <string>
#include "Sword.hpp"
#include "Shield.hpp"


class WeaponFactory{
  private:
    std::string category;
  public:

  Sword createSword();
  Shield createShield();
};
