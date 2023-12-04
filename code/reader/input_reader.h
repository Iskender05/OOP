#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../controller/playerController.h"
#include <functional>
#include "input.h"

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

class InputReader : public Input 
{
public:
    InputReader(const std::string& controlFile = "config.txt");
    using ControlMap = std::unordered_map<char, Action>;

    ControlMap controlMap_;
    char input;
    Action action;

    char in ( void ) const override;   
    uint8_t readInput( PlayerController *playerController);
private:

    // Загрузка клавиш управления из файла
    void loadControls(const std::string& controlFile);
};


#endif