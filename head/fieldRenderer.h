#ifndef FIELD_RENDERER_H
#define FIELD_RENDERER_H

#include "../head/tailmap.h"

class FieldRenderer
{
public:
    static void render(Tailmap& map, PlayerController& pc);
    static void clear_screen();
};




#endif