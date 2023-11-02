#include<iostream>
#include<ctime>
#include<cstdlib>

#include "../head/player.h"
#include "../head/directions.h"
#include "../head/playerController.h"
#include "../head/tailmap.h"
#include "../head/tail.h"
#include "../head/tailtype.h"
#include "../head/negative_event.h"
#include "../head/positive_event.h"
#include "../head/move_event.h"
#include "../head/level_generator.h"
#include "../head/fieldRenderer.h"


int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    EasyLevel easyLevel;
    HardLevel hardLevel;

    // Создание уровней
    Tailmap easyMap = LevelGenerator::createLevel(easyLevel, 20, 20);
    Tailmap hardMap = LevelGenerator::createLevel(hardLevel, 20, 20);

    // // Создание игроков и их контроллеров
    // Player player1;
    // PlayerController playerController1(&player1, &easyMap);

    Player player2;
    PlayerController playerController2(&player2, &hardMap);

    //  логика для игры на уровнях
    // playerController1.move(Direction::D_key);
    // playerController1.move(Direction::S_key);
    // playerController1.move(Direction::A_key);
    // playerController1.move(Direction::W_key);

    // playerController2.move(Direction::D_key);
    // playerController2.move(Direction::S_key);
    // playerController2.move(Direction::A_key);
    // playerController2.move(Direction::W_key);
    
    FieldRenderer::render(hardMap, playerController2);
    bool run = true;
    while ( run )
    {
        char key = getchar ();

        if ( key == 'q' )
            run = false;

        switch ( key )
        {
        case 'w':
            playerController2.move(Direction::W_key);
            break;
        
        case 'a':
            playerController2.move(Direction::A_key);
            break;

        case 'd':
            playerController2.move(Direction::D_key);
            break;

        case 's':
            playerController2.move(Direction::S_key);
            break;
        }

        // FieldRenderer::clear_screen();
        FieldRenderer::render(hardMap, playerController2);
    }
    

    // FieldRenderer::render(easyMap);
    // FieldRenderer::render(hardMap);

    return 0;
}




