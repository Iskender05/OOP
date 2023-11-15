#include "inputhandler.h"

InputHandler::InputHandler(const std::string& controlSchemeFile) {
    loadControlScheme(controlSchemeFile);
}

void InputHandler::loadControlScheme(const std::string& controlSchemeFile) {
    std::ifstream file(controlSchemeFile);
    char key;
    std::string command;
    while (file >> key >> command) {
        controlScheme[key] = command;
    }
}

char InputHandler::getUserInput() {
    char input;
    std::cin >> input;
    return input;
}

std::string InputHandler::matchCommand(char inputKey) {
    return controlScheme[inputKey];
}
