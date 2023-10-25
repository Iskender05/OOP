// game_level.cpp

#include "game_level.h"
#include "tailmap.h"
#include "tailtype.h"
#include "positive_event.h"
#include "negative_event.h"
#include <cstdlib>

void EasyLevel::createLevel(Tailmap& map) {
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
                }
            }
        }
    }
}

void HardLevel::createLevel(Tailmap& map) {
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
                }
            }
        }
    }
}
