#ifndef EK_LOG_H
#define EK_LOG_H

#include "base_mesg.h"
#include "../reader/input_reader.h"

class InputReader;
enum class Action : uint8_t;

class EnabelKeyLog : public BaseMesg
{
    InputReader* reader;
    std::vector<std::string> StrAction = {
        "moveUp", 
        "moveDown", 
        "moveLeft", 
        "moveRight", 
        "startGame", 
        "endGame" 
    };
    char input;
    Action action;

    public:
        EnabelKeyLog ( InputReader* reader );

        std::string message () override;

        virtual ~EnabelKeyLog() = default;
         // Переопределяем метод для проверки валидности сообщения
        bool isValid() const override { return valid; }
    
    private:
         bool valid = true;
};

#endif//EK_LOG_H