#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"
#include <string>

class BattleCard : public Card{
public:
     /*
     * C'tor of BattleCard class
    */
    BattleCard(std::string name, int force, int loot, int damage, bool isDragon);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player);

    BattleCard(const BattleCard&) = default;

    ~BattleCard() = default;

    BattleCard& operator=(const BattleCard& other) = default;


private:
    int m_force;
    int m_loot;
    int m_damage;
    bool m_isDragon;

    friend std::ostream& operator<<(std::ostream& os, const BattleCard& card);
};


#endif // BATTLE_CARD_H