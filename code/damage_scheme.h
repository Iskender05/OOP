#ifndef DAMAGE_SCHEME_H
#define DAMAGE_SCHEME_H

#include "../player/player.h"
#include <iostream>
#include <cmath>

class DamageInteractionScheme
{
    public:
        template<typename T>
        static void interact ( T& enemy, Player& player);
};

template<typename T>
void DamageInteractionScheme::interact( T& enemy, Player& player )
{
    if ( abs(player.getPostion().x - enemy.getPosition().x) <= 1 && abs(player.getPostion().y - enemy.getPosition().y) <= 1 )
    {
        player.takeDamage(10);
    }
}

#endif