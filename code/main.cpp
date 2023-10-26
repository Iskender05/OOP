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
    Player player;
    
    Tailmap map { Tailmap{23, 34, {2, 7}, {5, 6}} };
    map.at(pos_t(3, 3)) = TailType::WALL;
    map.at(pos_t(5, 5)) = TailType::WALL;
    map.at(pos_t(2, 8)) = TailType::AXID;
    map.at(pos_t(2, 8)) = new NegativeEvent;
    map.at(pos_t(2, 6)) = TailType::WATER;
    //map.at(pos_t(2, 6)) = new PositiveEvent;
    
    
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    EasyLevel easyLevel;
    HardLevel hardLevel;

    // Создание уровней
    Tailmap easyMap = LevelGenerator::createLevel(easyLevel, 10, 10);
    Tailmap hardMap = LevelGenerator::createLevel(hardLevel, 10, 10);

    // Создание игроков и их контроллеров
    Player player1;
    PlayerController playerController1(&player1, &easyMap);

    Player player2;
    PlayerController playerController2(&player2, &hardMap);

    // Ваша логика для игры на уровнях
    // Пример:
    playerController1.move(Direction::D_key);
    playerController1.move(Direction::S_key);
    playerController1.move(Direction::A_key);
    playerController1.move(Direction::W_key);

    playerController2.move(Direction::D_key);
    playerController2.move(Direction::S_key);
    playerController2.move(Direction::A_key);
    playerController2.move(Direction::W_key);
    

     //Tailmap map = generateBorderedMap(width, height);
    

    FieldRenderer::render(map);
    



    
    // map.at(pos_t(2, 8)).get_event()->applyEvent( player, map.at(pos_t(2, 8)) );

    // Tailmap map1 = Tailmap { 2, 3 };
    // Tailmap map2 = map1;
    
    // std::cout << map1.get_Height() << std::endl;
    // std::cout << map1.get_Width() << std::endl;

    // std::cout << map2.get_Height() << std::endl;
    // std::cout << map2.get_Width() << std::endl;

    PlayerController controller(&player, &map);
    
    player.setHP(10,50);
    player.setLvl(5);

    controller.move(Direction::W_key);

    
    
    // std::cout << "Player Info:" << std::endl;
    // std::cout << "Health: " << (int)player.getHP().hp << "\nDamage: " << (int)player.getHP().damage << std::endl;
    // std::cout << "Level: " << player.getLvl() << std::endl;
    // std::cout << "Position: (" << player.getPostion().x << ", " << player.getPostion().y << ")" << std::endl;

    return 0;
}




