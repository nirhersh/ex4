#ifndef Treasure_H
#define Treasure_H

#include "Card.h"
#include "../utilities.h"
#include <string>

class Treasure : public Card{
public:
    /*
    * C'tor of Treasure class
    */
    Treasure(std::string name = TREASURE_NAME, int coins = TREASURE_COINS);

    Treasure(const Treasure&) = default;

    ~Treasure() = default;

    Treasure& operator=(const Treasure&) = default;

    /*
     * Handling the player's applyEncounter with the Treasure card:
     *
     * @param player - The player.
    */
    void applyEncounter(Player& player) override;

private:
    int m_coins;
    static const int TREASURE_COINS = 10;
    static const std::string TREASURE_NAME;
};

#endif // Treasure_H