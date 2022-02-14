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
    int sel;
    bool continueLoop = true;

    while(continueLoop) {
        clear();
        std::cout << message;
        printMenu();
        sel = getSelection();

        if(sel == -1) { // if invalid selection
            message = "Please select a valid option!\n";
        } else { // if valid option
            clear();
            message = ""; // clear the message for next option call
            continueLoop = options[sel].start(message, *this); // Call the option method, if it returns true, then continue
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

void Menu::clear() {
    #if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
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