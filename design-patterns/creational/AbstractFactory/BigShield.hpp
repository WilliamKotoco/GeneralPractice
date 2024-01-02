#include "Shield.hpp"
#include <cstdio>

class BigShield : public Shield{
  private:
    int m_damage;

  public:
    BigShield(int protection, int damage): Shield(protection), m_damage(damage){}
    void defend() override{
      std::printf("You defended %d and attacked back %d", m_protection, m_damage);
    }
};
