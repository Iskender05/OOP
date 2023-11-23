#include "console_render.h"
#include<iostream>
#include <string>


void ConsoleRender::playerInfo(PlayerController &pc) const
{
    pos_t currentPosition = pc.get_player()->getPostion();
    int newX = currentPosition.x;
    int newY = currentPosition.y;
    std::cout << "Current HP: " << (int)pc.get_player()->getHP().hp << std::endl;
    std::cout << "Player moved to coordinates (" + std::to_string(newX) + ", " + std::to_string(newY) + ")." << std::endl;
}

void ConsoleRender::mapRender(Tailmap& map, PlayerController& pc) const
{
        for (uint16_t i = 0; i < map.get_Height(); i++){
        for (uint16_t j = 0; j < map.get_Width(); j++){
            if ( pc.get_player()->getPostion() == pos_t(j, i) )
            {
                std::cout << "@";
                continue;
            }

            if ( map.get_EndGame() == pos_t(j, i) )
            {
                std::cout << "G";
                continue;
            }
            
            switch (map.at(j, i).get_type())
            {
                case TailType::NORM:
                {
                    std::cout << " ";
                    break;
                }
                case TailType::WALL:
                {
                    std::cout << "#";
                    break;
                }
                case TailType::AXID:
                {
                    std::cout << "A";
                    break;
                }
                case TailType::WATER:
                {
                    std::cout << "~";
                    break;
                }
                default:{
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    if ( map.getTail(pc.get_player()->getPostion()).get_type() == TailType::NORM){
        pc.set_currentMesseege("");
    }

    std::cout << pc.get_currentMessege()<< std::endl;
}

void ConsoleRender::greeting() const 
{
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "Choose your level:"   << std::endl;
    std::cout << "1. Easy"              << std::endl;
    std::cout << "2. Hard"              << std::endl;
}


void ConsoleRender::choose() const
{
    std::cout <<  "Invalid choice. Starting with the easy level by default." << std::endl;
}

void ConsoleRender::offer() const
{
    std::cout << "Would you like to play again? (Y/N): ";
}

void ConsoleRender::goodbye() const
{
    std::cout << "Goodbye!" << std::endl;
}

void ConsoleRender::parting() const
{
    std::cout << "Thank you for playing!\n Press any key" << std::endl;
}

void ConsoleRender::lose() const
{
    std::cout << "You have been defeated!" << std::endl;
}

void ConsoleRender::win() const
{
    
}