#ifndef POSITIVE_EVENT_H
#define POSITIVE_EVENT_H

#include "../events/game_event.h"
#include "../player/player.h"
#include <iostream>

class PositiveEvent: public GameEvent
{
public:
    PositiveEvent () = default;
    virtual ~PositiveEvent () = default;
    
    void applyEvent(PlayerController& pc, Tail& tail) override;
};
 

 
#endif
