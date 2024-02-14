/// Interface for all Implementation classes.
#pragma once
#include <string>
class Implementation{
  public:
    virtual ~Implementation() {}
    virtual std::string operationImplementation() const = 0;

};
