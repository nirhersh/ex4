#include "Pitfall.h"

const std::string Pitfall::PITFALL_NAME = "Pitfall";

Pitfall::Pitfall(std::string name, int damage) : Card(name), m_damage(damage){}

void Pitfall::applyEncounter(Player& player){
    bool isRogue = false;
    Rogue* rogue = dynamic_cast<Rogue*>(&player);
    if(rogue != nullptr){
        isRogue = true;
    }else{
        player.damage(m_damage);
    }
    printPitfallMessage(isRogue);
}