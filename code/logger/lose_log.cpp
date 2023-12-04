#include "lose_log.h"

LoseLog::LoseLog(PlayerController* pc)
    : pc(pc)
{}

std::string LoseLog::message()
{

    int hp = pc->get_player()->getHP().hp;
    int level = pc->get_player()->getLvl();
    pos_t coordinates = pc->get_player()->getPostion();

    return "Проиграно на координатах: HP=" + std::to_string(hp) +
           ", Уровень=" + std::to_string(level) +
           ", Координаты=(" + std::to_string(coordinates.x) + ", " + std::to_string(coordinates.y) + ")\n";
}
