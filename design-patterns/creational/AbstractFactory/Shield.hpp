#include <cstdio>
#include<iostream>

class Shield{
  protected:
    int m_protection;
    
  public:
    Shield(int protection): m_protection(protection){}
    virtual void defend();
};
