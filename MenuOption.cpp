#include "MenuOption.h"

MenuOption::MenuOption(std::string optionName, std::function<bool(std::string &continueMessage, Menu &context)> function) {
    option = optionName;
    action = function;
}

bool MenuOption::start(std::string &continueMessage, Menu &context) {
    return action(continueMessage, context);
}

std::string MenuOption::getOptionName() {
    return option;
}