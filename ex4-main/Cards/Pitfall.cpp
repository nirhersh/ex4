#include "Pitfall.h"

const std::string Pitfall::PITFALL_NAME = "Pitfall";

Pitfall::Pitfall(std::string name) : Card(name){}

void Pitfall::applyEncounter(Player& player){
    bool isRogue = false;
    try{
        Rogue& rogue = dynamic_cast<Rogue&>(player);
        isRogue = true;
    }catch(std::bad_cast e){
        player.damage(PITFALL_DAMAGE);
    }
    printPitfallMessage(isRogue);
}