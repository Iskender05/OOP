#ifndef PUSH_SCHEME_H
#define PUSH_SCHEME_H

#include "../player/player.h"
#include <iostream>

class PushInteractScheme
{
    public:
        template<typename T>
        static void interact ( T& enemy, Player& player );
};

template<typename T>
void PushInteractScheme::interact ( T& enemy, Player& player )
{
    if ( abs(player.getPostion().x - enemy.getPosition().x) <= 1 && abs(player.getPostion().y - enemy.getPosition().y) <= 1 )
    {
        player.moveTo( player.getPostion().x + 1 , player.getPostion().y + 1 );
    }
}

#endif 