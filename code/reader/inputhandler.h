#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <fstream>
#include <unordered_map>


class InputHandler
{
private:
    std::unordered_map<char, std::string> controlScheme;

public:
    InputHandler(const std::string& controlSchemeFile);
    void loadControlScheme(const std::string& controlSchemeFile);
    char getUserInput();
    std::string matchCommand(char inputKey);
};



#endif
