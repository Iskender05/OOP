#ifndef TAIL_H
#define TAIL_H

#include "tailtype.h"


class Tail
{
private:
    TailType type;

public:
    // Tail () : type ( TailType::NORM ) {};
    Tail( TailType type = TailType::NORM );
    ~Tail() = default;

    void operator = ( const TailType type );
    
    void set_type ( TailType type );
    TailType get_type ( void );
};

#endif