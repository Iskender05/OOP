#ifndef GAME_EVENT_H
#define GAME_EVENT_H
   
#include "../controller/playerController.h"

class Tail;
class PlayerController;

class GameEvent
{
public:
    GameEvent () = default;
    virtual void applyEvent(PlayerController& pc, Tail& tail) = 0;
    virtual ~GameEvent() = default;
};

#endif