#ifndef TAIL_H
#define TAIL_H

#include "tailtype.h"
#include "../events/game_event.h"

class GameEvent;

class Tail
{
private:
    TailType type;
    GameEvent* event = nullptr;

    void clear_event ();

public:
    // Tail () : type ( TailType::NORM ) {};
    Tail( TailType type = TailType::NORM, GameEvent* event = nullptr );
    ~Tail() = default;           //Подумать

    void operator = ( const TailType type );
    void operator = ( GameEvent* event );
    
    void set_type ( TailType type );
    TailType get_type ( void );

    void set_event ( GameEvent* event );
    GameEvent* get_event ( void );
}; 

#endif