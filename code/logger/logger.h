#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "enable_key_log.h"
#include "lose_log.h"
#include "not_enable_key_log.h"
#include "win_log.h"
#include "new_game_log.h"
#include "output.h"
#include "terminal_out.h"
#include "file_out.h"


class Logger
{
private:
    Output* outwrite;
    std::vector<BaseMesg*> recentLogs;

public:
    Logger();
    ~Logger();

    void write_message(BaseMesg* message);
    void print_logs();
};

#endif // LOGGER_H
