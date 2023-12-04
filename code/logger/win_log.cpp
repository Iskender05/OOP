#include "win_log.h"

WinLog::WinLog ( PlayerController* pc )
    : pc ( pc )
{}

std::string WinLog::message ()
{
    return "Current HP: " + std::to_string ( pc->get_player()->getHP().hp ) + "\n" + std::to_string ( pc->get_player()->getLvl() );
}