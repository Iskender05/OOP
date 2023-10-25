#include "../head/tail.h"
#include "../head/tailtype.h"
//#include "event.h"
 

Tail::Tail( TailType type, GameEvent* event ) //type = TailType::NORM
    : type ( type ), event ( event )
{}

void Tail::clear_event ()
{
    if ( event != nullptr )
        delete event;
}

void Tail::set_type ( TailType type )
{
    if (type >= TailType::NORM && type <= TailType::WATER)
        this->type = type;
}

TailType Tail::get_type ( void )
{
    return type;
}

void Tail::operator = ( const TailType type )
{
    this->type = type;
}

void Tail::operator = ( GameEvent* event )
{
    clear_event ();
    this->event = event;
}

void Tail::set_event ( GameEvent* event )
{
    clear_event ();
    this->event = event;
}

GameEvent* Tail::get_event ( void )
{
    return event;
}