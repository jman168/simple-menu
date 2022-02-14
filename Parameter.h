#pragma once

#include <string>

#include "AbstractParameter.h"

class Menu;

template<class T>
class Parameter: public AbstractParameter {
    public:
        Parameter(std::string _name, T &_parameter);

        T *getParameter();

    private:
        T *parameter;
};

template<class T>
Parameter<T>::Parameter(std::string _name, T &_parameter): AbstractParameter(_name) {
    parameter = &_parameter;
}

template<class T>
T* Parameter<T>::getParameter() {
    return parameter;
}