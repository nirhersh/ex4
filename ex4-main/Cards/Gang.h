#ifndef GANG_H
#define GANG_H

#include "Card.h"
#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"
#include <vector>
#include <memory>

class Gang : public Card{
public:
    /*
    * C'tor of the Gang class
    *
    * @param name -  The gang card name, by default sets to "Gang"
    * 
    */ 
    Gang(std::string name = GANG_NAME);

    ~Gang() = default;

    /*
    * Copy C'tor of the Gang class
    *
    * @param gang1 - The gang to copy
    */
    Gang(Gang& gang1);

    /*
    * Assignment operator of the Gang class
    *
    * @param gang1 -  The gang to assign
    * 
    * @return - A reference to the newly assigned Gang
    */ 
    Gang& operator=(Gang& gang1);

    /*
    * a function that adds a monster to a gang
    *
    * @param newMonster -  a unique pointer to the new monster to add to the Gang
    */ 
    void addMonster(std::unique_ptr<BattleCard> newMonster);

    /*
    * a function that handles the encounter of the player with a gang
    * 
    * @param player -  a reference to the player who encountered the Gang
    */ 
    void applyEncounter(Player& player) const override;

    /*
    * Print function for thE Battle Card
    *
    * @param os - The stream to print to
    */
    void printCard(std::ostream& os) const override;

private:
    std::vector<std::unique_ptr<BattleCard>> m_gangMonsters;
    static const std::string GANG_NAME;
};

#endif // GANG_H