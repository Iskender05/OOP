#include<iostream>

#include "../head/Player.h"
#include "../head/Directions.h"
#include "../head/PlayerController.h"

int main() {
    Player player;
    PlayerController controller(&player);

    player.setHP(80, 50);
    player.setLvl(5);
    player.moveTo(10, 20);

    controller.move(Direction::D_key);

    std::cout << "Player Info:" << std::endl;
    std::cout << "Health: " << (int)player.getHP().hp << "\nDamage: " << (int)player.getHP().damage << std::endl;
    std::cout << "Level: " << player.getLvl() << std::endl;
    std::cout << "Position: (" << player.getPostion().x << ", " << player.getPostion().y << ")" << std::endl;

    return 0;
}




