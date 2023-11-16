#include "../game/game.h"
#include <iostream>


void Game::StartGame()
{
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "choose your level:"   << std::endl;
    std::cout << "1. Easy"              << std::endl;
    std::cout << "2. Hard"              << std::endl;

    ChooseLevel ();
}

void Game::ChooseLevel()
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
            PlayGame(easyMap, playerController);
            break;
        }
        case 2:
        {
            PlayerController playerController(&player, &hardMap);
            PlayGame(hardMap, playerController);
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

void Game::PlayGame(Tailmap &map, PlayerController &pc)
{
    uint64_t line_size = 0;
    while ( running )
    {
        CheckLose (*pc.get_player(), pc);
        CheckWin (*pc.get_player(), map, pc);

        FieldRenderer::render(map, pc);

        uint8_t ret = reader.readInput ( &pc ); 
        if ( ret == 1 )
            StartGame ();
        
        if ( ret == 2 )
            EndGame ( pc );

        FieldRenderer::clear_screen();
    }
}


void Game::EndGame(PlayerController &pc)
{
    running = false;

    std::cout << "Game over. Thank you for playing!" << std::endl;

    char choice;
    std::cout << "Would you like to play again? (Y/N): ";
    std::cin >> choice;
    
    reader.readInput ( &pc );

    std::cout << "Goodbye!" << std::endl;

    exit(0);
}

void Game::CheckLose(Player &player, PlayerController &pc)
{
    if (player.getHP().hp <= 0) 
    {
        std::cout << "You have been defeated! Game over." << std::endl;
        EndGame(pc);
    }
}


void Game::CheckWin(Player &player, Tailmap& map, PlayerController &pc)    // Понять !!!!!!
{
    if ( player.getPostion() == map.get_EndGame() )
    {
        std::cout << "You WIN! Game over." << std::endl;
        EndGame(pc);
    }
}