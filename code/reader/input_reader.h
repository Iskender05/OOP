#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../controller/playerController.h"
#include <functional>

class Game;

enum class Action : uint8_t 
{
    moveUp, 
    moveDown, 
    moveLeft, 
    moveRight, 
    startGame, 
    endGame
};
class InputReader 
{
public:
    InputReader(const std::string& controlFile = "config.txt");
    using ControlMap = std::unordered_map<char, Action>;

    ControlMap controlMap_;

    uint8_t readInput( PlayerController *playerController);
private:

    // Загрузка клавиш управления из файла
    void loadControls(const std::string& controlFile);
};


#endif