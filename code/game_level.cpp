#include "../head/game_level.h"
#include "../head/tailmap.h"
#include "../head/tailtype.h"
#include "../head/positive_event.h"
#include "../head/negative_event.h"
#include "../head/move_event.h"
#include <cstdlib>

void EasyLevel::createLevel(Tailmap& map) {
    // Заполнение оставшегося пространства случайными типами клеток
    for (uint16_t i = 1; i < map.get_Height() - 1; i++) {
        for (uint16_t j = 1; j < map.get_Width() - 1; j++) {
            // Вероятность появления кислоты или воды в этой клетке
            int randValue = std::rand() % 100;

            if (randValue < 20) {
                map.at(j, i) = TailType::AXID;
            } else if (randValue < 40) {
                map.at(j, i) = TailType::WATER;
            } else {
                map.at(j, i) = TailType::NORM;
            }
        }
    }
    
    // Реализация уровня Easy
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        for (uint16_t j = 0; j < map.get_Width(); j++) {
            if (i == 0 && j == 0) {
                map.at(j, i).set_type(TailType::START);
            } else if (i == map.get_Height() - 1 && j == map.get_Width() - 1) {
                map.at(j, i).set_type(TailType::END);
            } else {
                // Вероятность события 30%
                if (rand() % 100 < 30) {
                    map.at(j, i).set_event(new PositiveEvent());
                } else if (rand() % 100 < 10) { // Добавляем шанс события перемещения
                    map.at(j, i).set_event(new MoveEvent());
                }
            }
        }
    }
}

void HardLevel::createLevel(Tailmap& map) {
    // Заполнение оставшегося пространства случайными типами клеток
    for (uint16_t i = 1; i < map.get_Height() - 1; i++) {
        for (uint16_t j = 1; j < map.get_Width() - 1; j++) {
            // Вероятность появления кислоты или воды в этой клетке
            int randValue = std::rand() % 100;

            if (randValue < 20) {
                map.at(j, i) = TailType::AXID;
            } else if (randValue < 40) {
                map.at(j, i) = TailType::WATER;
            } else {
                map.at(j, i) = TailType::NORM;
            }
        }
    }
    
    // Реализация уровня Hard
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        for (uint16_t j = 0; j < map.get_Width(); j++) {
            if (i == 0 && j == 0) {
                map.at(j, i).set_type(TailType::START);
            } else if (i == map.get_Height() - 1 && j == map.get_Width() - 1) {
                map.at(j, i).set_type(TailType::END);
            } else {
                // Вероятность события 50%
                if (rand() % 100 < 50) {
                    map.at(j, i).set_event(new NegativeEvent());
                } else if (rand() % 100 < 10) { // Добавляем шанс события перемещения
                    map.at(j, i).set_event(new MoveEvent());
                }
            }
        }
    }
}
