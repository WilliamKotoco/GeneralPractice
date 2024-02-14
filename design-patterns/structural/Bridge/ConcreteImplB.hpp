
#include "Implementation.hpp"
class ConcreteImplB : public Implementation{
    std::string operationImplementation() const override{
        return "ConcreteImplementationB: operated on platform B";
    }
};
