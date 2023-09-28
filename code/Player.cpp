#include<iostream>
#include"../head/Player.h"


Player::Player() 
    : hitpoint(), lvl(START_LVL), position()
{}

void Player::setHP(const uint8_t newHealth, const uint8_t newDamage ) {
    if(newHealth >= MIN_HEALTH && newHealth <= MAX_HEALTH)
        hitpoint.hp = newHealth;

    if(newDamage >= MIN_DAMAGE && newDamage <= MAX_DAMAGE )
        hitpoint.damage = newDamage;
}

helth_t Player::getHP(){
    return hitpoint;
}

int Player::getLvl(){
    return lvl;
}

void Player::setLvl(int newLvl){
    if(newLvl >= START_LVL && newLvl <= MAX_LVL){
        lvl = newLvl;
    }
}

void Player::UpLvl(){
    if(lvl < MAX_LVL){
        lvl++;
    }
}

void Player::takeDamage(int amount){
    if (amount > 0){
        hitpoint.hp -= amount;
        if(hitpoint.hp < MIN_HEALTH){
            hitpoint.hp  = MIN_HEALTH;
            puts(" YOU DIED :( ");
        }
    }
}

void Player::moveTo(int newX, int newY){
    position.x = newX;
    position.y = newY;
}

void Player::moveTo( pos_t newPosition ){
    position.x = newPosition.x;
    position.y = newPosition.y;
}

pos_t Player::getPostion (){
    return position;
}