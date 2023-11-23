#ifndef GAME_RENDER_H
#define GAME_RENDER_H

#include "../controller/playerController.h"
#include "../map/tailmap.h"

class GameRender
{
public:
    virtual void playerInfo(PlayerController &pc) const = 0;
    virtual void mapRender(Tailmap& map, PlayerController& pc) const = 0;
    virtual void greeting() const = 0;
    virtual void choose() const = 0;
    virtual void offer() const = 0;
    virtual void goodbye() const = 0;
    virtual void parting() const = 0;
    virtual void win() const = 0;
    virtual void lose() const = 0;
};



#endif