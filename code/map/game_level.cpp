#include "game_level.h"

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

    // Заполнение  контура стенами
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        map.at(0, i) = TailType::WALL;
        map.at(map.get_Width() - 1, i) = TailType::WALL;
    }

    for (uint16_t j = 0; j <  map.get_Height(); j++) {
        map.at(j, 0) = TailType::WALL;
        map.at(j, map.get_Height() - 1) = TailType::WALL;
    }
    
    // Реализация уровня Easy
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        for (uint16_t j = 0; j < map.get_Width(); j++) {
            if (i == 0 && j == 0) {
                map.at(j, i).set_type(TailType::START);
            // } else if (i == map.get_Height() - 1 && j == map.get_Width() - 1) {
            } else if ( map.get_EndGame() == pos_t ( j, i ) ) {
                map.at(j, i).set_type(TailType::END);
            } else if ( map.at(j, i).get_type() == TailType::AXID ) {
                map.at(j, i).set_event(new NegativeEvent());
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

    // Заполнение  контура стенами
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        map.at(0, i) = TailType::WALL;
        map.at(map.get_Width() - 1, i) = TailType::WALL;
    }

    for (uint16_t j = 0; j <  map.get_Height(); j++) {
        map.at(j, 0) = TailType::WALL;
        map.at(j, map.get_Height() - 1) = TailType::WALL;
    }
    
    // Реализация уровня Hard
    for (uint16_t i = 0; i < map.get_Height(); i++) {
        for (uint16_t j = 0; j < map.get_Width(); j++) {
            if (i == 0 && j == 0) {
                map.at(j, i).set_type(TailType::START);
            // } else if (i == map.get_Height() - 1 && j == map.get_Width() - 1) {
            } else if ( map.get_EndGame() == pos_t ( j, i ) ) {
                map.at(j, i).set_type(TailType::END);
             } else if ( map.at(j, i).get_type() == TailType::AXID ) {
                map.at(j, i).set_event(new NegativeEvent());
            } else {
                // Вероятность события 50%
                if (rand() % 100 < 50) {
                    map.at(j, i).set_event(new PositiveEvent());
                } else if (rand() % 100 < 10) { // Добавляем шанс события перемещения
                    map.at(j, i).set_event(new MoveEvent());
                }
            }
        }
    }
}
