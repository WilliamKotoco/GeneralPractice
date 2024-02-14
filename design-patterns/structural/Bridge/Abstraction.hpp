#pragma once

#include "Implementation.hpp"
class Abstraction{
protected:
    Implementation *m_impl;

public:
    Abstraction(Implementation *impl) : m_impl(impl){}


    virtual std::string Operation() const {
        return "Abstraction. Base operator with: \n" +
        m_impl->operationImplementation();
    }
};