#ifndef POSITIVE_EVENT_H
#define POSITIVE_EVENT_H

#include "game_event.h"

class PositiveEvent: public GameEvent
{
public:
    PositiveEvent () = default;
    virtual ~PositiveEvent () = default;
    
    void applyEvent(Player& Player, Tail& tail) override;
};


 
#endif
