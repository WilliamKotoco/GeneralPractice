#pragma  once
class RoundPeg
{
  private:
    int radius;
  
  public:
    RoundPeg() {}
    RoundPeg(int radius_) : radius(radius_) {}
   virtual int getRadius() {return radius;}


};
