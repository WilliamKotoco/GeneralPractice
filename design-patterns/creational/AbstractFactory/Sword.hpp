#include <cstdio>
#include <iostream>
#include <string>
class Sword{
  protected:
    int m_damage;

  public:
    Sword(int damage): m_damage(damage){}
    virtual void attack();

};
