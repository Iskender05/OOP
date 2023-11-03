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
    // PlayerController playerController1(&player1, &easyMap);     // Для изи мапы 

    Player player2;
    PlayerController playerController2(&player2, &hardMap);        // Для хард мапы 

    FieldRenderer::render(hardMap, playerController2);
    bool run = true;
    uint64_t line_size = 0;
    while ( run )
    {
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

        FieldRenderer::render(hardMap, playerController2);
    }

    return 0;
}




