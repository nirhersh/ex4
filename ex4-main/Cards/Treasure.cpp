#include "Treasure.h"

const std::string Treasure::TREASURE_NAME = "Treasure";

Treasure::Treasure(std::string name, int coins) : Card(name), m_coins(coins){}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}