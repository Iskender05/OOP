#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../player/player.h"
#include "directions.h"
#include "../map/tailmap.h"
#include "../events/game_event.h"
#include <string>

class Tailmap;

class PlayerController
{
private:
    Player* player;
    Tailmap* map;

    std::string currentMessage = "level Started"; 
    
    const int move_value = 1;
    const int health_value = 1;

public:
    PlayerController(Player* Player, Tailmap* map);
    
    void move(Direction direction);
    void dinamic_health();
    void dinamic_lvl(int lvl_value);

    Player* get_player(void);

    void checkAndApplyEvent();

    std::string get_currentMessege();
    void set_currentMesseege(std::string newString);

    

   
};

#endif
