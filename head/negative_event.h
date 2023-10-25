#ifndef NEGATIVE_EVENT_H
#define NEGATIVE_EVENT_H

#include "game_event.h"

class NegativeEvent : public GameEvent {
public:
    NegativeEvent () = default;
    virtual ~NegativeEvent () = default;

    void applyEvent(Player& player, Tail& tail) override;
};

#endif
 