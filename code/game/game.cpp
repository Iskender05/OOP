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
            FieldRenderer::render(easyMap, playerController);
            PlayGame(easyMap, playerController);
            break;
        }
        case 2:
        {
            PlayerController playerController(&player, &hardMap);
            FieldRenderer::render(hardMap, playerController);
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
    bool run = true;
    uint64_t line_size = 0;
    while ( run )
    {
        CheckLose (*pc.get_player());
        CheckWin (*pc.get_player(), map);

        char key = getchar ();
        line_size++;

        if ( line_size > 1 && key != '\n' )
            continue;

        if ( key == '\n' ){
            line_size = 0;
            continue;
        }

        if ( key == 'q' )
            run = false;

        FieldRenderer::clear_screen();

        switch ( key )
        {
        case 'w':
            pc.move(Direction::W_key);
            break;
        
        case 'a':
            pc.move(Direction::A_key);
            break;

        case 'd':
            pc.move(Direction::D_key);
            break;

        case 's':
            pc.move(Direction::S_key);
            break;
        }

        FieldRenderer::render(map, pc);
    }
}


void Game::EndGame()
{
    std::cout << "Game over. Thank you for playing!" << std::endl;

    char choice;
    std::cout << "Would you like to play again? (Y/N): ";
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        StartGame(); // Начать новую игру
    } else {
        std::cout << "Goodbye!" << std::endl;

        exit(0); 
    }
}

void Game::CheckLose(Player &player)
{
    if (player.getHP().hp <= 0) 
    {
        std::cout << "You have been defeated! Game over." << std::endl;
        EndGame();
    }
}


void Game::CheckWin(Player &player, Tailmap& map)    // Понять !!!!!!
{
    if ( player.getPostion() == map.get_EndGame() )
    {
        std::cout << "You WIN! Game over." << std::endl;
        EndGame();
    }
}