#include "../head/level_generator.h"
#include "../head/tailmap.h"

Tailmap LevelGenerator::createLevel(GameLevel& level, uint16_t width, uint16_t height) {
    Tailmap map(width, height, pos_t( 1, 1 ), pos_t( width - 2, height - 2 ) );
    level.createLevel(map);
    return map;
}
