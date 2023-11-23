#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../controller/playerController.h"
#include "../map/fieldRenderer.h"
#include "../map/game_level.h"
#include "../map/level_generator.h"
#include "../reader/input_reader.h"
#include "game_observer.h"
#include "observer.h"

class PlayerController;
class FieldRenderer;
class GameLevel;
class InputReader;

class Game { 
public:
    bool running = true;
    InputReader reader{"config.txt"};
    std::vector<GameObserver*> gameObservers;

    Game () = default;

    void executeCommand(const std::string& command);
    void StartGame();
    void ChooseLevel();
    void PlayGame(Tailmap& map, PlayerController& pc);
    void EndGame(PlayerController &pc);
    void CheckLose(PlayerController &pc);
    void CheckWin(Tailmap& map, PlayerController &pc);

    void registerGameObserver(GameObserver* observer);
    void notifyGameObservers(const std::string& eventMessage);
};

#endif