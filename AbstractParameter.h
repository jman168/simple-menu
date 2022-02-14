#pragma once

#include <string>

class AbstractParameter {
    public:
        AbstractParameter(std::string _name);
        std::string getName();
    
    private:
        std::string name;
};