#include "tracker.h"
#include "../map/console_render.h"

Trakcer::Trakcer(GameRender &render, PlayerController &pc, Tailmap &map): 
    render(render), 
    pc(pc),
    map(map)
{}

void Trakcer::observer(Types types)
{
    switch(types){
        case Types::CHOOSE:
        {
            render.choose();
            break;
        }
        case Types::OFFER:
        {
            render.offer();
            break;
        }
        case Types::BYE:
        {
            render.goodbye();
            break;
        }
        case Types::START:
        {
            render.greeting();
            break;
        }
        case Types::END:
        {
            render.parting();
            break;
        }
        case Types::CHECK_LOSE:
        {
            render.lose();
            break;
        }
        case Types::PLAY:
        {
            system ( "clear" );

            render.playerInfo(pc);
            render.mapRender(map, pc);
            break;
        }
    }
}
