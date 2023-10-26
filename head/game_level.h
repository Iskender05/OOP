#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "../head/tailmap.h"

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