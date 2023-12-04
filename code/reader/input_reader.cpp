#include "input_reader.h"

void InputReader::loadControls(const std::string& controlFile) {
    std::ifstream file(controlFile);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл управления" << std::endl;
        return;
    }

    char key;
    std::string command;

    std::unordered_map<std::string, Action> commandMap = {
        {"moveUp", Action::moveUp},
        {"moveDown", Action::moveDown},
        {"moveLeft", Action::moveLeft},
        {"moveRight", Action::moveRight},
        {"startGame", Action::startGame},
        {"quit", Action::endGame}
    };

    std::unordered_map<char, bool> keyAssigned;

    while (file >> key >> command) {
        // Проверка на валидность клавиши
        if (!isalpha(key)) {
            std::cerr << "Недопустимая клавиша: " << key << std::endl;
            continue;
        }

        // Проверка на валидность команды
        auto commandIt = commandMap.find(command);
        if (commandIt == commandMap.end()) {
            std::cerr << "Недопустимая команда: " << command << std::endl;
            continue;
        }

        // Проверка на дублирование присвоений клавиш
        if (keyAssigned[key]) {
            std::cerr << "Дублирование присвоения клавиши: " << key << std::endl;
            continue;
        }

        controlMap_[key] = commandIt->second;
        keyAssigned[key] = true;
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
uint8_t InputReader::readInput(PlayerController *playerController, Logger* log ) {
    char input = in();
    this->input = input;

    auto it = controlMap_.find(input);
    if (it != controlMap_.end()) {
        switch(it->second) {
            case Action::moveUp:
                playerController->move(Direction::W_key);
                this->action = Action::moveUp;
                log->write_message( new EnabelKeyLog(this) );
                break;
            case Action::moveDown:
                playerController->move(Direction::S_key);
                this->action = Action::moveDown;
                log->write_message( new EnabelKeyLog(this) );
                break;
            case Action::moveLeft:
                playerController->move(Direction::A_key);
                this->action = Action::moveLeft;
                log->write_message( new EnabelKeyLog(this) );
                break;
            case Action::moveRight:
                playerController->move(Direction::D_key);
                this->action = Action::moveRight;
                log->write_message( new EnabelKeyLog(this) );
                break;
            case Action::startGame:
                return 1;
                break;
            case Action::endGame:
                return 2;
                break;
            default:
                log->write_message( new NotEnabelKeyLog(this) );
                break;
        }
    }
    return 0;
}