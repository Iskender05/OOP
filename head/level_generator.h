#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "../head/game_level.h"
 
class LevelGenerator {
public:
    static Tailmap createLevel(GameLevel& level, uint16_t width, uint16_t height);
};

#endif
