#include "Treasure.h"

const std::string Treasure::TREASURE_NAME = "Treasure";

Treasure::Treasure(std::string name) : Card(name){}

void Treasure::applyEncounter(Player& player){
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}