#ifndef Goblin_H
#define Goblin_H

#include "BattleCard.h"
#include <string>

class Goblin : public BattleCard{
public:
     /*
     * C'tor of Goblin class
    */
    Goblin(std::string name = GOBLIN_NAME, int force = GOBLIN_FORCE, int loot=GOBLIN_LOOT, int damage=GOBLIN_DAMAGE);

    Goblin(const Goblin&) = default;

    ~Goblin() = default;

    Goblin& operator=(const Goblin& other) = default;


private:
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_DAMAGE = 10;
    static const std::string GOBLIN_NAME;
};


#endif // Goblin_H