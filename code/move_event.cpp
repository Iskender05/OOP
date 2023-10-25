#include "move_event.h"
#include "player.h"
#include "tailmap.h"
#include "game_event.h" 
#include <cstdlib>
#include <iostream>

 
void MoveEvent::applyEvent(Player& player, Tail& tail) {
    // Пример изменения координат игрока на поле: случайное перемещение
    
    std::cout << "MoveEvent active!" << std::endl;

    pos_t currentPosition = player.getPostion();
    int newX = currentPosition.x + (rand() % 3) - 1; // Случайное смещение по X (-1, 0, 1)
    int newY = currentPosition.y + (rand() % 3) - 1; // Случайное смещение по Y (-1, 0, 1)



     //Проверьте, что новые координаты находятся в пределах карты
     if (newX >= 0 && newX < MAX_WIDTH && newY >= 0 && newY < MAX_HEIGHT) {
         player.moveTo(newX, newY);
     }
}

