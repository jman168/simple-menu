#include "AbstractParameter.h"

AbstractParameter::AbstractParameter(std::string _name) {
    name = _name;
}

std::string AbstractParameter::getName() {
    return name;
}