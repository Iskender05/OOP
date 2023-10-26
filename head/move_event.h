#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#include "../head/game_event.h"

class MoveEvent : public GameEvent {
public:
    MoveEvent () = default;
    virtual ~MoveEvent () = default;

    void applyEvent(Player& player, Tail& tail) override;
};

#endif
 