#include "Sword.hpp"
#include <cstdio>

class BigSword : public Sword{
  private:
    int m_weight ;
  public:
    BigSword(int damage, int weight): Sword(damage), m_weight(weight) {}
    
    void attack() override{
      std::printf("You damaged %d the enemy and %d your backs!", m_damage, m_weight);
    }
};
