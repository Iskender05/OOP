#include<iostream>

#include "../head/player.h"
#include "../head/directions.h"
#include "../head/playerController.h"
#include "../head/tailmap.h"
#include "../head/tail.h"
#include "../head/tailtype.h"

int main() {
    Player player;
    PlayerController controller(&player);
    Tailmap map (10, 10); // Заполнение поля игрока 

    map.at(pos_t(3, 3)) = TailType::WALL;
    map.at(pos_t(5, 5)) = TailType::WALL;

    Tailmap map2 { Tailmap{23, 34, {1, 4}, {5, 6}} };
    map2.at(pos_t(3, 3)) = TailType::AXID;

    std::cout << (int) static_cast<uint8_t> ( map2.at ( 3, 3 ).get_type() ) << std::endl;
    std::cout << (int) static_cast<uint8_t> ( map.at ( 5, 5 ).get_type() ) << std::endl;

    player.setHP(10,50);
    player.setLvl(5);

    controller.move(Direction::D_key);

    std::cout << "Player Info:" << std::endl;
    std::cout << "Health: " << (int)player.getHP().hp << "\nDamage: " << (int)player.getHP().damage << std::endl;
    std::cout << "Level: " << player.getLvl() << std::endl;
    std::cout << "Position: (" << player.getPostion().x << ", " << player.getPostion().y << ")" << std::endl;

    
    // pos_t position_to_check = player.getPostion();
    // if (position_to_check.x >= 0 && position_to_check.x < map.get_Width() && position_to_check.y >= 0 && position_to_check.y < map.get_Height())
    // {
    //     Tail &tail = map.get_tail(position_to_check);
    // }
    // else
    // {
    //     std::cout << "Invalid position for checking on the map." << std::endl;
    // }



    return 0;
}




