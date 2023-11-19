#include "move_event.h"
#include <cstdlib>
#include <iostream>

 
void MoveEvent::applyEvent(PlayerController& pc, Tail& tail) {
    // Пример изменения координат игрока на поле: случайное перемещение
    
    //std::cout << "MoveEvent active!" << std::endl;

    pos_t currentPosition = pc.get_player()->getPostion();
    int newX = currentPosition.x + (rand() % 3) - 1; // Случайное смещение по X (-1, 0, 1)
    int newY = currentPosition.y + (rand() % 3) - 1; // Случайное смещение по Y (-1, 0, 1)

     //Проверьте, что новые координаты находятся в пределах карты
     if (newX >= 0 && newX < MAX_WIDTH && newY >= 0 && newY < MAX_HEIGHT) {
         pc.get_player()->moveTo(newX, newY);
         std::cout << "Player moved to coordinates (" << newX << ", " << newY << ")." << std::endl;
     }
}

