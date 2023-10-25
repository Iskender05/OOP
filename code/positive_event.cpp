#include "positive_event.h"
#include "player.h"
#include <iostream>
 
void PositiveEvent::applyEvent(Player& player, Tail& tail){
    std::cout << "Positive event active!" << std::endl;

    helth_t currentHP = player.getHP();
    player.setHP(currentHP.hp + 10, currentHP.damage);

    int currentLevel = player.getLvl();
    player.setLvl(currentLevel + 1);
}