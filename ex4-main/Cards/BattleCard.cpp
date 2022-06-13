#include "BattleCard.h"
#include "Dragon.h"

BattleCard::BattleCard(std::string name, int force, int loot, int damage) :
 Card(name), m_force(force), m_loot(loot), m_damage(damage){};

void BattleCard::applyEncounter(Player& player){
    // check if battle card is a dragon
    bool isDragon = false;
    const Dragon* dragon = dynamic_cast<const Dragon*>(this);
    if(dragon != nullptr){
        isDragon = true;
    }
    if(player.getAttackStrength() >= m_force){
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), this->getName());
    }else{
        printLossBattle(player.getName(), this->getName());
        if(isDragon){
            player.knockOut();
            return;
        }
        player.damage(m_damage);
    }
}

void BattleCard::printCard(std::ostream& os) const{
    bool isDragon = false;
    const Dragon* dragon = dynamic_cast<const Dragon*>(this);
    if(dragon != nullptr){
        isDragon = true;
    }
    printMonsterDetails(os, m_force, m_damage, m_loot, isDragon);
}
