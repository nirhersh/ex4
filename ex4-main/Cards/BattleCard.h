#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "Card.h"
#include <string>

class BattleCard : public Card{
public:
     /*
     * C'tor of BattleCard class
    */
    BattleCard(std::string name, int force, int loot, int damage);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player);

    BattleCard(const BattleCard&) = default;

    ~BattleCard() = default;

    BattleCard& operator=(const BattleCard& other) = default;

protected:
    /*
    * Print function for thE Battle Card
    *
    * @param os - The stream to print to
    */
    void printCard(std::ostream& os) const override;


private:
    int m_force;
    int m_loot;
    int m_damage;
};


#endif // BATTLE_CARD_H