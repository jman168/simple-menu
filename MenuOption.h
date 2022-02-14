#pragma once

#include <functional>
#include <string>
#include <iostream>

#include "Menu.h"

class Menu;

/**
 * @brief Designed for use with the Menu class.
 * The Menu class will call a MenuOption and run it's function when an option is selected.
 * 
 */
class MenuOption {
    public:
        MenuOption(std::string optionName, std::function<bool(std::string &continueMessage, Menu &context)> function);
        
        bool start(std::string &continueMessage, Menu &context);
        std::string getOptionName();

    private:
        std::string option;
        std::function<bool(std::string &continueMessage, Menu &context)> action;
};