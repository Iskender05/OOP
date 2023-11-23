#include "../game/game.h"
#include <iostream>


void Game::StartGame()
{
    running = true;
    ConsoleRender render;

    render.greeting ();

    ChooseLevel( render );
}

void Game::ChooseLevel( GameRender& render )
{
    int choise;
    std::cin >> choise;

    EasyLevel easyLevel;
    HardLevel hardLevel;

    // Создание уровней
    Tailmap easyMap = LevelGenerator::createLevel(easyLevel, 20, 20);
    Tailmap hardMap = LevelGenerator::createLevel(hardLevel, 20, 20);
    Player player;

    switch (choise)
    {
        case 1:
        {
            PlayerController playerController(&player, &easyMap);
            Trakcer htrack { render, playerController, easyMap };
            PlayGame(easyMap, playerController, htrack);
            break;
        }
        case 2:
        {
            PlayerController playerController(&player, &hardMap);
            Trakcer htrack { render, playerController, hardMap };
            PlayGame(hardMap, playerController, htrack);
            break;
        }
        default:
        {
            std::cout <<  "Invalid choice. Starting with the easy level by default." << std::endl;
            break;
        }
    }
}

void Game::executeCommand(const std::string& command) {
    std::cout << "Executing command: " << command << std::endl;
}

void Game::PlayGame(Tailmap &map, PlayerController &pc, Trakcer &htrack)
{
    while ( running )
    {
        CheckLose (pc, htrack);
        CheckWin (map, pc, htrack);

        if ( !running )
            break;

        htrack.observer ( Types::PLAY );
        uint8_t ret = reader.readInput ( &pc );        
        if ( ret == 2 )
            EndGame ( pc );
    }

    htrack.observer ( Types::OFFER );
    char choice = reader.readInput ( &pc );

    if ( choice ) {
        StartGame();
    } else {
        htrack.observer ( Types::BYE );
    }
}


void Game::EndGame(PlayerController &pc)
{
    running = false;

    std::cout << "Thank you for playing!\n Press any key" << std::endl;
}


void Game::CheckLose(PlayerController &pc, Trakcer &htrack)
{
    if (pc.get_player()->getHP().hp <= 0) 
    {
        htrack.observer ( Types::CHECK_LOSE );
        EndGame(pc);
    }
}


void Game::CheckWin(Tailmap& map, PlayerController &pc, Trakcer &htrack) 
{
    if ( pc.get_player()->getPostion() == map.get_EndGame() )
    {
        htrack.observer ( Types::CHECK_WIN );
        EndGame(pc);
    }
}