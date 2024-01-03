#pragma once
/// The builder class specifies methods for creating different
/// parts of the Product objects
class Builder{
  public:
    virtual void producePartA() const = 0;
    virtual void producePartB() const = 0;
    virtual void producePartC() const = 0;

};
