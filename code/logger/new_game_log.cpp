#include "new_game_log.h"

NewGameLog::NewGameLog(PlayerController* pc, Tailmap* tailmap)
    : pc(pc), map(tailmap)
{}

std::string NewGameLog::message()
{
    return "New game started. Field size: " + std::to_string(map->get_Width()) +
           "x" + std::to_string(map->get_Height()) +
           ". Player started at position (" + std::to_string(map->get_Spawn().x) +
           ", " + std::to_string(map->get_Spawn().y) + ").\n";
}
