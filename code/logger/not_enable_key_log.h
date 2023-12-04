#ifndef NOT_EK_LOG_H
#define NOT_EK_LOG_H

#include "base_mesg.h"
#include "../reader/input_reader.h"

class InputReader;

class NotEnabelKeyLog : public BaseMesg
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

    public:
        NotEnabelKeyLog ( InputReader* reader );

        std::string message () override;

        virtual ~NotEnabelKeyLog() = default;
         // Переопределяем метод для проверки валидности сообщения
        bool isValid() const override { return valid; }
    
    private:
        bool valid = false; // Добавим флаг для отслеживания валидности сообщения
};

#endif//NOT_EK_LOG_H