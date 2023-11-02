#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../head/player.h"
#include "../head/directions.h"
#include "../head/tailmap.h"
#include "../head/game_event.h"

class Tailmap;

class PlayerController
{
private:
    Player* player;
    Tailmap* map;
 
    const int move_value = 1;
    const int health_value = 1;

public:
    PlayerController(Player* Player, Tailmap* map);
    
    void move(Direction direction);
    void dinamic_health();
    void dinamic_lvl(int lvl_value);

    Player* get_player ( void );

    void checkAndApplyEvent();
};


#endif

