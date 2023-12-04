#ifndef WIN_LOG_H
#define WIN_LOG_H

#include "base_mesg.h"
#include "../controller/playerController.h"

class WinLog : public BaseMesg
{
    PlayerController* pc;

public:
    WinLog ( PlayerController* pc );

    std::string message () override;
    
    virtual ~WinLog () = default;
};


#endif//WIN_LOG_H