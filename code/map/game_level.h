#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "tailmap.h"
#include "tailtype.h"
#include "../events/positive_event.h"
#include "../events/negative_event.h"
#include "../events/move_event.h"
#include <cstdlib>

class GameLevel
{
public:
    virtual void createLevel(Tailmap& map) = 0;
};

class EasyLevel : public GameLevel
{
public:
    void createLevel(Tailmap& map) override;

};

class HardLevel : public GameLevel 
{
public:
    void createLevel(Tailmap& map) override;
};



#endif