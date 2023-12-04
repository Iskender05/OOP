#ifndef EK_LOG_H
#define EK_LOG_H

#include "base_mesg.h"
#include "../reader/input_reader.h"

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

    public:
        EnabelKeyLog ( InputReader* reader );

        std::string message () override;

        virtual ~EnabelKeyLog() = default;
};

#endif//EK_LOG_H