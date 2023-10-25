#ifndef GAME_EVENT_H
#define GAME_EVENT_H
  
#include "player.h"
#include "tail.h"

class Tail;
class Player;

class GameEvent
{
public:
    GameEvent () = default;
    virtual void applyEvent(Player& Player, Tail& tail) = 0;
    virtual ~GameEvent() = default;
};

#endif