#ifndef OUTPUT_H
#define OUTPUT_H

#include "base_mesg.h"

class Output
{
public:
    Output() = default;
    virtual ~Output() = default;

    virtual void out(BaseMesg& message) = 0;
};


#endif
