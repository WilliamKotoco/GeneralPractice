/// this is optional

#include "Abstraction.hpp"

class ExtendedAbstraction : public Abstraction{

public:
    ExtendedAbstraction(Implementation *impl) : Abstraction(impl){}

std::string Operation() const override{
    return "ExtendedAbstraction: Extended operation with \n"+
    m_impl->operationImplementation();
}

};
