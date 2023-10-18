#ifndef PLAYER_H
#define PLAYER_H

#define MAX_DAMAGE 50
#define MIN_DAMAGE 0
#define START_HEALTH 100
#define START_LVL 1
#define MAX_LVL 80
#define START_X 0
#define START_Y 0
#define MIN_HEALTH 0
#define MAX_HEALTH 100

#include <cstdint>

typedef struct __Helth
{
    uint8_t hp;
    uint8_t damage;

    __Helth () : hp ( MAX_HEALTH ), damage ( MIN_DAMAGE ) {}
} helth_t;


typedef struct __Position
{
    int64_t x;
    int64_t y;

    __Position () : x ( START_X ), y ( START_Y ) {}
    __Position ( int64_t x, int64_t y ) : x ( x ), y ( y ) {}
    void operator = ( __Position pos ) { x = pos.x; y = pos.y; }

    void set_pos ( int64_t x, int64_t y ) { this->x = x; this->y = y; }
} pos_t;

class Player
{
    friend class PlayerController;
 
    private:
        int lvl;

        helth_t hitpoint;
        pos_t position;

        void moveTo(int newX, int newY);
        void moveTo(pos_t newPosition);

    public:
        Player();

        void    setHP(const uint8_t newHealth, const uint8_t newDamage );        
        helth_t getHP();

        void    setLvl(int newLvl);
        int     getLvl();

        void UpLvl();

        void takeDamage(int amouth);

        pos_t getPostion ();
};

#endif