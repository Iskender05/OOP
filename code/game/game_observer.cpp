#include "game_observer.h"
#include <iostream>

GameObserver::GameObserver(PlayerController* pc, Tailmap* map) : playerController(pc), tailmap(map) {}


void GameObserver::onPlayerMove(const pos_t& newPosition) 
{
    std::cout << "Player moved to coordinates (" << newPosition.x << ", " << newPosition.y << ")." << std::endl;
}


void GameObserver::onWin() 
{
    std::cout << "Congratulations! You won the game.\n PRESS ANY KEY" << std::endl;
}


void GameObserver::onLose() 
{
    std::cout << "Game over. You lost.\n PRESS ANY KEY" << std::endl;
}


void GameObserver::onEventTriggered(const std::string& eventMessage) 
{
    std::cout << "Event triggered: " << eventMessage << std::endl;
}
