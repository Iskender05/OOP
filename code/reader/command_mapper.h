#ifndef COMMAND_MAPPER_H
#define COMMAND_MAPPER_H


#include "game.h"


class CommandMapper
{
private:
    Game& Game;

public:
    CommandMapper(Game& game);
    void mapCommand(const std::string& command);

};



#endif