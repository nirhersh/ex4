#include "Goblin.h"

const std::string Goblin::GOBLIN_NAME = "Goblin";

Goblin::Goblin(std::string name, int force, int loot, int damage) : BattleCard(name, force, loot, damage){}