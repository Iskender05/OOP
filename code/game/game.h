#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../controller/playerController.h"
#include "../map/fieldRenderer.h"
#include "../map/game_level.h"
#include "../map/level_generator.h"
#include "../reader/input_reader.h"

class PlayerController;
class FieldRenderer;
class GameLevel;
class InputReader;

class Game {
public:
    bool running = true;
    InputReader reader{"config.txt"};

    Game () = default;

    void executeCommand(const std::string& command);
    void StartGame();
    void ChooseLevel();
    void PlayGame(Tailmap& map, PlayerController& pc);
    void EndGame(PlayerController &pc);
    void CheckLose(PlayerController &pc);
    void CheckWin(Tailmap& map, PlayerController &pc);

};

#endif