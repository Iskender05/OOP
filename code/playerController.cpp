#include<iostream>
#include "../head/player.h"
#include "../head/playerController.h"
#include "../head/directions.h"


PlayerController::PlayerController(Player* player, Tailmap* map) : player(player), map(map) {
    if (player != nullptr){
        this->player = player;
    }
    else{
        puts("NULLPTR");
    }

    player->moveTo ( map->get_Spawn () );
}

void PlayerController::move(Direction direction){
    pos_t currentPosition = player->getPostion();

    switch (direction)
    {
        case Direction::W_key:
        {
            pos_t next_pos = { currentPosition.x, currentPosition.y - move_value };
            if ( map->at ( next_pos ).get_type () != TailType::WALL )
                player->moveTo( next_pos );
            
            break;
        }
        case Direction::S_key:
        {
            pos_t next_pos = { currentPosition.x, currentPosition.y + move_value };
            if ( map->at ( next_pos ).get_type () != TailType::WALL )
                player->moveTo( next_pos );
            
            break;
        }
        case Direction::A_key:
        {
            pos_t next_pos = { currentPosition.x - move_value , currentPosition.y };
            if ( map->at ( next_pos ).get_type () != TailType::WALL )
                player->moveTo( next_pos );
            
            break;
        }
        case Direction::D_key:
        {
            pos_t next_pos = { currentPosition.x + move_value , currentPosition.y };
            if ( map->at ( next_pos ).get_type () != TailType::WALL )
                player->moveTo( next_pos );
            
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