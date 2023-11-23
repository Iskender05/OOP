#ifndef OBSERVER_H
#define OBSERVER_H


#include <iostream>
#include "../controller/playerController.h"
#include "../map/tailmap.h"

class Observer {
public:
    virtual void onPlayerMove(const pos_t& newPosition) = 0;
    virtual void onWin() = 0;
    virtual void onLose() = 0;
    virtual void onEventTriggered(const std::string& eventMessage) = 0;
};

#endif
