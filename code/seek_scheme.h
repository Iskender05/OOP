#ifndef SEEK_SCHEME_H
#define SEEK_SCHEME_H

#include "../player/player.h"
#include <iostream>

class SeekPlayerControlScheme
{
    public:
        template<typename T>
        void move( T& enemy, Player& player );
};

template <typename T>
void SeekPlayerControlScheme::move(T& enemy, Player& player) {
    auto enemyPos = enemy.getPosition();
    auto playerPos = player.getPostion();

    int deltaX = playerPos.x - enemyPos.x;
    int deltaY = playerPos.y - enemyPos.y;

    if (deltaX > 0) {
        enemy.move(pos_t(enemyPos.x + 1, enemyPos.y));
    } else if (deltaX < 0) {
        enemy.move(pos_t(enemyPos.x - 1, enemyPos.y));
    }

    if (deltaY > 0) {
        enemy.move(pos_t(enemyPos.x, enemyPos.y + 1));
    } else if (deltaY < 0) {
        enemy.move(pos_t(enemyPos.x, enemyPos.y - 1));
    }
}

#endif