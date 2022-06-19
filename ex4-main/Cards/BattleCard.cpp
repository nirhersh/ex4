#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"

BattleCard::BattleCard(std::string name, int force, int loot, int damage, bool inGang) :
 Card(name), m_force(force), m_loot(loot), m_damage(damage), m_inGang(inGang){}

void BattleCard::applyEncounter(Player& player) const{
    // check if battle card is a dragon
    bool isDragon = false;
    bool isVampire = false;
    const Dragon* dragon = dynamic_cast<const Dragon*>(this);
    const Vampire* vampire = dynamic_cast<const Vampire*>(this);
    if(dragon != nullptr){
        isDragon = true;
    }
    if(vampire != nullptr){
        isVampire = true;
    }
    if(player.getAttackStrength() >= m_force && !player.getNeedToLose()){
        player.addCoins(m_loot);
        if (!m_inGang){
            player.levelUp();
            printWinBattle(player.getName(), this->getName());
        }
    }else{
        printLossBattle(player.getName(), this->getName());
        if(isDragon){
            player.knockOut();
            return;
        }
        if(isVampire){
            player.weaken();
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

int BattleCard::getForce() const
{
    return m_force;
}

void BattleCard::setInGang(bool inGang)
{
    m_inGang = inGang;
}
