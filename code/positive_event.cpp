#include "positive_event.h"
#include "player.h"
#include <iostream>
 
void PositiveEvent::applyEvent(PlayerController& pc, Tail& tail){
    std::cout << "Positive event active!" << std::endl;

    helth_t currentHP = pc.get_player()->getHP();
    pc.get_player()->setHP(currentHP.hp + 10, currentHP.damage);

    int currentLevel = pc.get_player()->getLvl();
    pc.get_player()->setLvl(currentLevel + 1);

    // Вывод текущего здоровья игрока
    std::cout << "Current HP: " << (int)pc.get_player()->getHP().hp << std::endl;
}