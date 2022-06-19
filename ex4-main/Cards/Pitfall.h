#ifndef Pitfall_H
#define Pitfall_H

#include "Card.h"
#include "../Players/Rogue.h"
#include "../utilities.h"
#include <string>

class Pitfall : public Card{
public:
    /*
    * C'tor of Pitfall class
    */
    Pitfall(std::string name = PITFALL_NAME, int damage = PITFALL_DAMAGE);

    Pitfall(const Pitfall&) = default;

    ~Pitfall() = default;

    Pitfall& operator=(const Pitfall&) = default;

    /*
     * Handling the player's applyEncounter with the Pitfall card:
     *
     * @param player - The player.
    */
    void applyEncounter(Player& player) override;

private:
    int m_damage;
    static const int PITFALL_DAMAGE = 10;
    static const std::string PITFALL_NAME;
};

#endif // Pitfall_H