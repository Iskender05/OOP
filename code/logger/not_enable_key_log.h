#ifndef NOT_EK_LOG_H
#define NOT_EK_LOG_H

#include "base_mesg.h"
#include "../reader/input_reader.h"

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

    public:
        NotEnabelKeyLog ( InputReader* reader );

        std::string message () override;

        virtual ~NotEnabelKeyLog() = default;
};

#endif//NOT_EK_LOG_H