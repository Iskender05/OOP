#ifndef CONSOLE_RENDER_H
#define CONSOLE_RENDER_H

#include "game_render.h"
#include "fieldRenderer.h"

class ConsoleRender :public GameRender
{
public:
    void playerInfo(PlayerController &pc) const override;
    void mapRender(Tailmap& map, PlayerController& pc) const override;
    void greeting() const override;
    void choose() const override;
    void offer() const override;
    void goodbye() const override;
    void parting() const override;
    void win() const override;
    void lose() const override;
};


#endif