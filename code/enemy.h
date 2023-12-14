#ifndef ENEMY_H
#define ENEMY_H

#include "../player/player.h"
#include "../map/tailmap.h"
#include "damage_scheme.h"
#include "push_scheme.h"
#include "random_scheme.h"
#include "seek_scheme.h"

#define gotoxy(x,y,z) std::printf("\033[%d;%dH%c", (y), (x), (z))
#define restore() std::printf("\033[u")

template<typename ControlScheme, typename InteractionScheme>
class Enemy
{
    public:
        Enemy ( const pos_t& position) : position(position) {}
        void update(Player& player);
        void move(pos_t newPosition);
        void interact(Player& player);
        void render (Tailmap& map);

        pos_t getPosition() const;
    
    private:
        pos_t position;
        ControlScheme controlScheme;
        InteractionScheme interactionScheme;
};

template<typename ControlScheme, typename InteractionScheme>
void Enemy<ControlScheme, InteractionScheme>::update( Player& player )
{
    controlScheme.move( *this, player );
    interact ( player );
}


template<typename ControlScheme, typename InteractionScheme>
pos_t Enemy<ControlScheme, InteractionScheme>::getPosition() const
{
    return position;
}

template<typename ControlScheme, typename InteractionScheme>
void Enemy<ControlScheme, InteractionScheme>::move(pos_t newPosition)
{
    const int mapWidth = 20;  
    const int mapHeight = 20; 

 
    if (newPosition.x >= 0 && newPosition.x < mapWidth &&
        newPosition.y >= 0 && newPosition.y < mapHeight)
    {
        position = newPosition;
    }
}


template <typename ControlScheme, typename InteractionScheme>
void Enemy<ControlScheme, InteractionScheme>::interact(Player &player)
{
    interactionScheme.interact( *this, const_cast<Player&>(player));
}

template <typename ControlScheme, typename InteractionScheme>
void Enemy<ControlScheme, InteractionScheme>::render(Tailmap& map)
{
    for (uint16_t i = 0; i < map.get_Height(); i++){
        for (uint16_t j = 0; j < map.get_Width(); j++){
            if ( getPosition() == pos_t(j, i) )
                gotoxy( j, i, 'X');
                restore();
        }
    }
}

#endif