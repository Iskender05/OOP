#ifndef TAILTYPE_H
#define TAILTYPE_H

#include <cstdint>


enum class TailType : uint8_t
{
    NORM = 0,
    WALL,
    AXID,
    WATER,
    START,
    END
};

#endif