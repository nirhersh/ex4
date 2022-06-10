#include "BattleCard.h"

BattleCard::BattleCard(std::string name, int force, int loot, int damage, bool isDragon) :
 Card(name), m_force(force), m_loot(loot), m_damage(damage), m_isDragon(isDragon){};

void BattleCard::applyEncounter(Player& player){
    if(player.getAttackStrength() >= m_force){
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), this->getName());
    }else{
        printLossBattle(player.getName(), this->getName());
        if(m_isDragon){
            player.knockOut();
            return;
        }
        player.damage(m_damage);
    }
}

std::ostream& operator<<(std::ostream& os, const BattleCard& card){
    printMonsterDetails(os, card.m_force, card.m_damage, card.m_loot, card.m_isDragon);
    return os;
}
