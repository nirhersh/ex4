#include "Vampire.h"

const std::string Vampire::VAMPIRE_NAME = "Vampire";

Vampire::Vampire(std::string name, int force, int loot, int damage, bool isDragon) :
 BattleCard(name, force, loot, damage, isDragon){}