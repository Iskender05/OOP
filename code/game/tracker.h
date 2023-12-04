#ifndef TRACKER_H 
#define TRACKER_H

#include "types.h"
#include "../map/fieldRenderer.h"
#include "../map/game_render.h"
#include "../controller/playerController.h"

class Trakcer
{
public:
    void observer(Types types);
    Trakcer(GameRender &render, PlayerController &pc, Tailmap &map);

private:
    GameRender &render;
    PlayerController &pc;
    Tailmap &map;
};



#endif