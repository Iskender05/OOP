#ifndef TERMINAL_OUT_H
#define TERMINAL_OUT_H

#include "output.h"
#include "base_mesg.h"
#include <iostream>

class TerminalOut : public Output
{
public:
    TerminalOut() = default;
    virtual ~TerminalOut() = default;

    void out(BaseMesg& message) override;
};

#endif