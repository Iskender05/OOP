#include "../head/tail.h"
#include "../head/tailtype.h"

Tail::Tail( TailType type ) //type = TailType::NORM
    : type ( type )
{}

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