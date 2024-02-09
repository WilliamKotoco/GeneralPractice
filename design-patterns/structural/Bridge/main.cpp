#include "Abstraction.hpp"
#include "ConcreteImplA.hpp"
#include "ConcreteImplB.hpp"
#include "ExtendedAbstraction.hpp"

#include <iostream>
int main()
{
    Implementation *impl = new ConcreteImplA;
    Abstraction *abstraction = new Abstraction(impl);
    std::cout << abstraction->Operation() << "\n";

    delete impl;
    delete abstraction;

    impl = new ConcreteImplB;
    abstraction = new ExtendedAbstraction(impl);
    std::cout << abstraction->Operation();
    return 0;
}
