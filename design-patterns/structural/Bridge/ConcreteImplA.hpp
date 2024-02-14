
#include "Implementation.hpp"

class ConcreteImplA : public Implementation{
public:
    std::string operationImplementation() const override{
        return "ConcreteImplementationA: Result on platform A";


    }
};
