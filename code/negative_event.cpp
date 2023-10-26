#include "../head/negative_event.h"
#include <iostream>

void NegativeEvent::applyEvent(Player& player, Tail& tail) {
    std::cout << "Negative event active!" << std::endl;
    
    //  уменьшение здоровья и уровня игрока
    helth_t currentHP = player.getHP();
    player.setHP(currentHP.hp - 10, currentHP.damage);

    int currentLevel = player.getLvl();
    player.setLvl(currentLevel - 1);

    // Вывод текущего здоровья игрока
    std::cout << "Current HP: " << (int)player.getHP().hp << std::endl;
}
 