#include "MenuOption.h"

MenuOption::MenuOption(std::string optionName, std::function<bool(std::string &continueMessage)> function) {
    option = optionName;
    action = function;
}

bool MenuOption::start(std::string &continueMessage) {
    return action(continueMessage);
}

std::string MenuOption::getOptionName() {
    return option;
}