#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"
#include <string>

class BattleCard : public Card{
public:
     /*
     * C'tor of BattleCard class
    */
    BattleCard(std::string name, int force, int loot, int damage, bool inGang = false);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player) const;

    BattleCard(const BattleCard&) = default;

    ~BattleCard() = default;

    BattleCard& operator=(const BattleCard& other) = default;

    /*
    * Print function for thE Battle Card
    *
    * @param os - The stream to print to
    */
    void printCard(std::ostream& os) const override;

    /*
    * Gets the monster's force
    * 
    * @return - The monster's force
    */ 
    int getForce() const;

    /*
    * a function to set if the monster is a part of a Gang card
    *
    * @param inGang - a boolean, true if the monster is in a gang, false otherwise
    */ 
    void setInGang(bool inGang);

private:
    int m_force;
    int m_loot;
    int m_damage;
    bool m_inGang;
};


#endif // BATTLE_CARD_H