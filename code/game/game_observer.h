#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "observer.h"

class PlayerController;
class Tailmap;

class GameObserver : public Observer {
private:
    PlayerController* playerController;
    Tailmap* tailmap;

public:
    GameObserver(PlayerController* pc, Tailmap* map);

    void onPlayerMove(const pos_t& newPosition) override;
    void onWin() override;
    void onLose() override;
    void onEventTriggered(const std::string& eventMessage) override;
};

#endif
