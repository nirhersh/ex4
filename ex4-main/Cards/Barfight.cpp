#include "Barfight.h"

const std::string Barfight::BARFIGHT_NAME = "Barfight";

Barfight::Barfight(std::string name, int damage) : Card(name), m_damage(damage){}

void Barfight::applyEncounter(Player& player){
    bool isFighter = false;
    const Fighter* fighter = dynamic_cast<const Fighter*>(&player);
    if(fighter != nullptr){
        isFighter = true;
    }else{
        player.damage(m_damage);
    }
    printBarfightMessage(isFighter);
}
