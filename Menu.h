#pragma once

#include <string>
#include <vector>

#include "MenuOption.h"
#include "AbstractParameter.h"
#include "Parameter.h"

class MenuOption;

/**
 * @brief A basic menu class that deals with input validation and allows for easy menu creation in the style required for C++ class
 * 
 */
class Menu {
    public:
        Menu();

        void start();
        void addOption(MenuOption option);

        template<class T>
        void addParameter(std::string name, T &parameter);

        template<class T>
        T *getParameter(std::string name);

    private:
        void clear();
        void printMenu();
        int getSelection();

        std::string message;
        std::vector<MenuOption> options;
        std::vector<AbstractParameter *> parameters;
};

/**
 * @brief Adds a parameter to the parameter list who's pointer can then be accessed by name
 * 
 * @tparam T Datatype of the parameter
 * @param name Name of the parameter
 * @param parameter Parameter
 */
template<class T>
void Menu::addParameter(std::string name, T &parameter) {
    parameters.push_back(new Parameter<T>(name, parameter));
}

/**
 * @brief Accesses a parameter pointer by name
 * 
 * @tparam T Datatype of the parameter
 * @param name Name of the parameter
 * @return T* Pointer retrieved (nullptr if pointer is not found)
 */
template<class T>
T *Menu::getParameter(std::string name) {
    T *out = nullptr; // Create a pointer with for the data to be stored

    for(AbstractParameter * parameter: parameters) {
        if((*parameter).getName() == name) {
            // If a matching abstract parameter is found, cast it to a parameter of the data type, get the parameter, and set it to the output pointer
            out = (*(Parameter<T> *)parameter).getParameter(); 
        }
    }

    return out; // Return the data
}