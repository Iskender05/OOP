#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../head/player.h"
#include "../head/directions.h"
//#include "../head/tailmap.h"


class PlayerController
{
private:
    Player* player;

    const int move_value = 1;
    const int health_value = 1;

public:
    PlayerController(Player* Player);
    
    void move(Direction direction);
    void dinamic_health();
    void dinamic_lvl(int lvl_value);
};

#endif

