#include "Dragon.h"

const std::string Dragon::DRAGON_NAME = "Dragon";

Dragon::Dragon(std::string name, int force, int loot, int damage, bool isDragon) :
 BattleCard(name, force, loot, damage, isDragon){}
 