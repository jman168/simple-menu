#include "Menu.h"

// Constructor
Menu::Menu() {
    message = "";
}

/**
 * @brief Starts the menu method.
 * The menu will not return unless an option returns false.
 * 
 */
void Menu::start() {
    system("clear");
    std::cout << message;
    printMenu();
    int sel = getSelection();

    if(sel < 0) {
        message = "Please select a valid option!\n";
        start();
    } else {
        system("clear");
        if(options[sel].start(message)) {
            start();
        }
    }
}

/**
 * @brief Adds and option to the menu
 * 
 * @param option 
 */
void Menu::addOption(MenuOption option) {
    options.push_back(option);
}

void Menu::printMenu() {
    for(int i = 0; i < options.size(); i++) {
        std::cout << (i+1) << ". " << options[i].getOptionName() << "\n";
    }
}

int Menu::getSelection() {
    int selection;

    std::cout << "Please enter an option (1-" << options.size() << "): ";
    std::cin >> selection;
    std::cin.ignore();

    if(selection <= 0 || selection > options.size())
        return -1;
    else
        return selection-1;
}