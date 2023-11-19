#include "input_reader.h"

void InputReader::loadControls(const std::string& controlFile) {
    std::ifstream file(controlFile);
    if (!file.is_open()) {
        std::cerr << "Failed to open control file" << std::endl;
        return;
    }

    char key;
    std::string command;

    while (file >> key >> command) {
        if (command == "moveUp")
            controlMap_[key] = Action::moveUp;
        if (command == "moveDown")
            controlMap_[key] = Action::moveDown;
        if (command == "moveLeft")
            controlMap_[key] = Action::moveLeft;
        if (command == "moveRight")
            controlMap_[key] = Action::moveRight;
        if (command == "startGame")
            controlMap_[key] = Action::startGame;
        if (command == "quit")
            controlMap_[key] = Action::endGame;
    }

    file.close();
}
InputReader::InputReader(const std::string& controlFile) {
    loadControls(controlFile);
}

char InputReader::in(void) const
{
    char input;
    std::cin >> input;

    return input;
}

// Считывание команды с клавиатуры
uint8_t InputReader::readInput(PlayerController *playerController) {
    char input = in();

    auto it = controlMap_.find(input);
    if (it != controlMap_.end()) {
        switch(it->second) {
            case Action::moveUp:
                playerController->move(Direction::W_key);
                break;
            case Action::moveDown:
                playerController->move(Direction::S_key);
                break;
            case Action::moveLeft:
                playerController->move(Direction::A_key);
                break;
            case Action::moveRight:
                playerController->move(Direction::D_key);
                break;
            case Action::startGame:
                return 1;
                break;
            case Action::endGame:
                return 2;
                break;
            default:
                break;
        }
    }
    
    return 0;
}