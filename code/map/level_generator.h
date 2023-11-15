#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "game_level.h"
#include "tailmap.h"
 
class LevelGenerator {
public:
    static Tailmap createLevel(GameLevel& level, uint16_t width, uint16_t height);
};

#endif
