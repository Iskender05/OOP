#include "../head/fieldRenderer.h"
#include <iostream>
#include <ctime>


void FieldRenderer::render(Tailmap& map)
{
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
   
   
   
    for (uint16_t i = 0; i < map.get_Height(); i++){
        for (uint16_t j = 0; j < map.get_Width(); j++){
            switch (map.at(j, i).get_type())
            {
                case TailType::NORM:
                {
                    std::cout << " ";
                    break;
                }
                case TailType::WALL:
                {
                    std::cout << "#";
                    break;
                }
                case TailType::AXID:
                {
                    std::cout << "A";
                    break;
                }
                case TailType::WATER:
                {
                    std::cout << "~";
                    break;
                }
                default:{
                    std::cout << " ";
                }

            }
        }
        std::cout << std::endl;
    }

}

Tailmap generateBorderedMap(uint16_t width, uint16_t height) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Tailmap map(width, height);

    // Заполнение внешнего контура стенами
    for (uint16_t i = 0; i < height; i++) {
        map.at(0, i) = TailType::WALL;
        map.at(width - 1, i) = TailType::WALL;
    }

    for (uint16_t j = 0; j < width; j++) {
        map.at(j, 0) = TailType::WALL;
        map.at(j, height - 1) = TailType::WALL;
    }

    // Заполнение оставшегося пространства случайными типами клеток
    for (uint16_t i = 1; i < height - 1; i++) {
        for (uint16_t j = 1; j < width - 1; j++) {
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

    return map;
}