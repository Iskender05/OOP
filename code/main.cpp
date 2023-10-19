#include<iostream>

#include "../head/player.h"
#include "../head/directions.h"
#include "../head/playerController.h"
#include "../head/tailmap.h"
#include "../head/tail.h"
#include "../head/tailtype.h"

int main() {
    Player player;
    
    Tailmap map { Tailmap{23, 34, {2, 3}, {5, 6}} };
    map.at(pos_t(3, 3)) = TailType::WALL;
    map.at(pos_t(5, 5)) = TailType::WALL;
    map.at(pos_t(2, 8)) = TailType::AXID;

    PlayerController controller(&player, &map);
    
    player.setHP(10,50);
    player.setLvl(5);

    controller.move(Direction::D_key);

    std::cout << "Player Info:" << std::endl;
    std::cout << "Health: " << (int)player.getHP().hp << "\nDamage: " << (int)player.getHP().damage << std::endl;
    std::cout << "Level: " << player.getLvl() << std::endl;
    std::cout << "Position: (" << player.getPostion().x << ", " << player.getPostion().y << ")" << std::endl;

    return 0;
}




