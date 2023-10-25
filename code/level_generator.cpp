#include "level_generator.h"
#include "tailmap.h"

Tailmap LevelGenerator::createLevel(GameLevel& level, uint16_t width, uint16_t height) {
    Tailmap map(width, height);
    level.createLevel(map);
    return map;
}
