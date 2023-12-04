#ifndef LOSE_LOG_H
#define LOSE_LOG_H

#include "base_mesg.h"
#include "../controller/playerController.h"

class LoseLog : public BaseMesg
{
    PlayerController* pc;

public:
    LoseLog ( PlayerController* pc );

    std::string message () override;
    virtual ~LoseLog () = default;
};


#endif//LOSE_LOG_H