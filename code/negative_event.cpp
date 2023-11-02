#include "../head/negative_event.h"
#include <iostream>

void NegativeEvent::applyEvent(PlayerController& pc, Tail& tail) {
    std::cout << "Negative event active!" << std::endl;
    

    //  уменьшение здоровья и уровня игрока
    helth_t currentHP = pc.get_player()->getHP();
    pc.get_player()->setHP(currentHP.hp - 10, currentHP.damage);            // Добавить проерку на проигрыш
    if (currentHP.hp == 0){
        std::cout << "YOU LOSE :()" << std::endl;
    }


    int currentLevel = pc.get_player()->getLvl();
    pc.get_player()->setLvl(currentLevel - 1);

    // Вывод текущего здоровья игрока
    std::cout << "Current HP: " << (int)pc.get_player()->getHP().hp << std::endl;
}
 