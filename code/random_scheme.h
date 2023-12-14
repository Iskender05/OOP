#ifndef RANDOM_SCHEME_H
#define RANDOM_SCHEME_H

#include "../player/player.h"
#include <random>

class RandomWanderControlScheme
{
    public:
        template<typename T>
        void move( T& enemy, Player& Player );
};

template <typename T>
void RandomWanderControlScheme::move(T& enemy, Player& player) {
    int randomX = rand() % 3 - 1;
    int randomY = rand() % 3 - 1;

    enemy.move(pos_t(enemy.getPosition().x + randomX, enemy.getPosition().y + randomY));
}

#endif 