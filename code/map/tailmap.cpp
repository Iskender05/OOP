#include "tailmap.h"
//#include "tailmap.h"

#include <string.h>
#include <iostream>

uint16_t Tailmap::get_Width(){
    return width;

}

uint16_t Tailmap::get_Height(){
    return height;

}

pos_t Tailmap::get_Spawn(){
    return spawn;
}


pos_t Tailmap::get_EndGame(){
    return end_game;
}

Tailmap::Tailmap ( uint16_t width, uint16_t height )
{
    if ( width < MIN_WIDTH || width > MAX_WIDTH )
        this->width = DEFAULT_WIDTH;
    else
        this->width = width;

    if ( height < MIN_HEALTH || height > MAX_HEIGHT )
        this->height = DEFAULT_HEIGHT;
    else
        this->height = height;

    create_map ();
}

void Tailmap::create_map ()
{
    map = new Tail*[height];
    for ( uint16_t i = 0; i < height; i++ )
        map[i] = new Tail[width];

    for ( uint16_t i = 0; i < height; i++ )
        for ( uint16_t j = 0; i < width; i++ )
            map[i][j].set_type ( TailType::NORM );
}

Tailmap::Tailmap ( uint16_t width, uint16_t height, pos_t spawn, pos_t end_game )
    : Tailmap ( width, height )
{
    this->spawn = spawn;
    this->end_game = end_game;
}

Tailmap::Tailmap(const Tailmap &tmp)
    : Tailmap ( tmp.width, tmp.height, tmp.spawn, tmp.end_game )
{
    std::cout << "Copy class" << std::endl;

    copy_map ( tmp );
}

void Tailmap::swap_map ( const Tailmap &tmp )
{
    // memcpy ( map, tmp.map, height );
    // for ( uint8_t i = 0; i < height; i++ )
    //     memcpy ( map[i], tmp.map[i], width );
    map = tmp.map;

    // copy_map ( tmp );
}

void Tailmap::copy_map ( const Tailmap &tmp )
{
    for ( uint16_t i = 0; i < height; i++ )
        for ( uint16_t j = 0; j < width; j++ )
            map[i][j] = tmp.map[i][j];
}

void Tailmap::operator=(const Tailmap &tmp)
{
    del_map ();

    width = tmp.width;
    height = tmp.height;

    create_map ();

    copy_map ( tmp );

    spawn = tmp.spawn;
    end_game = tmp.end_game;
}

Tailmap::Tailmap(Tailmap &&tmp)
    : width ( tmp.width ), height ( tmp.height )
    , spawn ( tmp.spawn ), end_game ( tmp.spawn )
{
    // std::cout << "Move class" << std::endl;

    width = tmp.width;
    height = tmp.height;
    spawn = tmp.spawn;
    end_game = tmp.end_game;

    // create_map ();
    swap_map ( tmp );

    tmp.map = nullptr;

    tmp.width = tmp.height = 0;
    tmp.spawn = { 0, 0 };
    tmp.end_game = { 0, 0 };
}

void Tailmap::operator=(Tailmap &&tmp)
{
    del_map ();

    width = tmp.width;
    height = tmp.height;
    spawn = tmp.spawn;
    end_game = tmp.end_game;

    // create_map ();
    swap_map ( tmp );

    tmp.map = nullptr;

    tmp.width = tmp.height = 0;
    tmp.spawn = { 0, 0 };
    tmp.end_game = { 0, 0 };
}

Tailmap::~Tailmap()
{
    del_map ();
}

void Tailmap::del_map ( void )
{
    // std::cout << "Delete class" << std::endl;

    for ( uint16_t i = 0; i < height; i++ )
        delete map[i];

    delete[] map;
}

Tail& Tailmap::at ( uint16_t width, uint16_t height )
{
    // Вернуть ссылку на клетку в соответствии с переданными координатами (position)

    if (width >= 0 && width < this->width && height >= 0 && height < this->height) {
        return map[height][width];
    } else {
        // Проверка случая, когда переданы недопустимые координаты.
        // Можно вернуть, например, клетку с типом по умолчанию.
        return map[0][0];
    }
}

Tail& Tailmap::at ( pos_t position )
{
    return at ( position.x, position.y );
}