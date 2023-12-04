#ifndef NEW_GAME_LOG_H
#define NEW_GAME_LOG_H

#include "base_mesg.h"
#include "../controller/playerController.h"
#include "../map/tailmap.h" 

class NewGameLog : public BaseMesg
{
    PlayerController* pc;
    Tailmap* map;

public:
    NewGameLog ( PlayerController* pc, Tailmap* map);

    std::string message () override;
    virtual ~NewGameLog () = default;
};


#endif//NEW_GAME_LOG_H