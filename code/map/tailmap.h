#ifndef TAILMAP_H
#define TAILMAP_H

#include "tail.h"
#include "tailtype.h"
#include "../player/player.h"
  
#define DEFAULT_WIDTH 255
#define DEFAULT_HEIGHT 255
#define MIN_WIDTH 1
#define MAX_WIDTH 655335
#define MIN_HEIGHT 1
#define MAX_HEIGHT 65535

class Tail;

class Tailmap
{
private:

    Tail** map = nullptr;
    uint16_t width = 0, height = 0;

    pos_t spawn = {0, 0};
    pos_t end_game = {0, 0};

    void del_map ( void );
    void create_map ( void );
    void swap_map ( const Tailmap &tmp );
    void copy_map ( const Tailmap &tmp );

public:
    uint16_t get_Width();
    uint16_t get_Height();

    pos_t get_Spawn();
    pos_t get_EndGame();

    Tail& at ( uint16_t width, uint16_t height );
    Tail& at ( pos_t position );

    Tailmap ( void ) = default;
    Tailmap ( uint16_t width, uint16_t height );
    Tailmap ( uint16_t width , uint16_t height, pos_t spawn, pos_t end_game );

    Tailmap ( const Tailmap& tmp );                 // Tailmap map { Tailmap ( 2, 3 ) }
    void operator = ( const Tailmap& tmp );         // Tailmap map = Tailmap { 2, 3 }

    Tailmap ( Tailmap&& tmp );
    void operator = ( Tailmap&& tmp );

    ~Tailmap();
};

#endif