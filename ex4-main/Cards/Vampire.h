#ifndef Vampire_H
#define Vampire_H

#include "BattleCard.h"
#include <string>

class Vampire : public BattleCard{
public:
     /*
     * C'tor of Vampire class
    */
    Vampire(std::string name = VAMPIRE_NAME, int force = VAMPIRE_FORCE, int loot=VAMPIRE_LOOT, int damage=VAMPIRE_DAMAGE,
     bool isDragon=false);

    Vampire(const Vampire&) = default;

    ~Vampire() = default;

    Vampire& operator=(const Vampire& other) = default;


private:
    static const int VAMPIRE_FORCE = 6;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_DAMAGE = 10;
    static const std::string VAMPIRE_NAME;
};


#endif // Vampire_H