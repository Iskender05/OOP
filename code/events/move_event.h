#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#include "game_event.h"
#include "../player/player.h" 
#include "../map/tailmap.h"
#include "game_event.h" 
#include <cstdlib>
#include <iostream>

class MoveEvent : public GameEvent {
public:
    MoveEvent () = default;
    virtual ~MoveEvent () = default;

    void applyEvent(PlayerController& pc, Tail& tail) override;
};

#endif
  