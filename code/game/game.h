#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "../controller/playerController.h"
#include "../map/fieldRenderer.h"
#include "../map/game_level.h"
#include "../map/level_generator.h"

class PlayerController;
class FieldRenderer;
class GameLevel;

class Game 
{
public:
    void executeCommand(const std::string& command);
    
    void StartGame();
    void ChooseLevel();
    void PlayGame(Tailmap &map, PlayerController &pc);
    void EndGame();
    void CheckLose(Player &Player);
    void CheckWin(Player &player, Tailmap& map);
};

#endif
