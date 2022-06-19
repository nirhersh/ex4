#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"
#include <string>

class Dragon : public BattleCard{
public:
     /*
     * C'tor of Dragon class
    */
    Dragon(std::string name = DRAGON_NAME, int force = DRAGON_FORCE, int loot=DRAGON_LOOT, int damage=DRAGON_DAMAGE);

    Dragon(const Dragon&) = default;

    ~Dragon() = default;

    Dragon& operator=(const Dragon& other) = default;

private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DAMAGE = 100000;
    static const std::string DRAGON_NAME;
};


#endif // DRAGON_H