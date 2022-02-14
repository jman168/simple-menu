#pragma once

#include <string>
#include <vector>

#include "MenuOption.h"

/**
 * @brief A basic menu class that deals with input validation and allows for easy menu creation in the style required for C++ class
 * 
 */
class Menu {
    public:
        Menu();

        void start();
        void addOption(MenuOption option);

    private:
        void printMenu();
        int getSelection();

        std::string message;
        std::vector<MenuOption> options;
};