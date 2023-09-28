#include "../head/Player.h"
#include "../head/PlayerController.h"
#include "../head/Directions.h"


PlayerController::PlayerController(Player* player) : player(player) {}

void PlayerController::move(Direction direction){
    pos_t currentPosition = player->getPostion();

    switch (direction)
    {
        case Direction::W_key:
        {
            player->moveTo(currentPosition.x, currentPosition.y - move_value);
            break;
        }
        case Direction::S_key:
        {
            player->moveTo(currentPosition.x, currentPosition.y + move_value);
            break;
        }
        case Direction::A_key:
        {
            player->moveTo(currentPosition.x - move_value, currentPosition.y);
            break;
        }
        case Direction::D_key:
        {
            player->moveTo(currentPosition.x + move_value, currentPosition.y);
            break;
        }
        default:{
            break;
        }
    }

}

void PlayerController::dinamic_health() {
    helth_t currntHP = player->getHP();
    player->setHP(currntHP.hp - health_value, currntHP.damage);
}

void PlayerController::dinamic_lvl(int lvl_value){
    player->setLvl(player->getLvl() + lvl_value);
}