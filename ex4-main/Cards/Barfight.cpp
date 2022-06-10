#include "Barfight.h"

const std::string Barfight::BARFIGHT_NAME = "Barfight";

Barfight::Barfight(std::string name) : Card(name){}

void Barfight::applyEncounter(Player& player){
    bool isFighter = false;
    try{
        const Fighter& fighter = dynamic_cast<const Fighter&>(player);
        isFighter = true;
    }catch(std::bad_cast e){
        player.damage(HP_LOSS);
    }
    printBarfightMessage(isFighter);
}