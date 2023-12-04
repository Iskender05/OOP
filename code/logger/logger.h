#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "enable_key_log.h"
#include "lose_log.h"
#include "not_enable_key_log.h"
#include "win_log.h"

class Output
{
public:
    Output () = default;
    virtual ~Output () = default;

    virtual void out ( BaseMesg& message ) = 0;
};

class FileOut : public Output
{
    std::ofstream file;

public:
    FileOut( std::string file_path );
    virtual ~FileOut();

    void out ( BaseMesg& message ) override;
};

class TerminalOut : public Output
{
public:
    TerminalOut() = default;
    virtual ~TerminalOut() = default;

    void out ( BaseMesg& message ) override;
};

class Logger
{
private:
    Output* outwrite;

public:
    Logger();
    ~Logger();

    void write_message ( BaseMesg* message );
};

#endif//LOGGER_H