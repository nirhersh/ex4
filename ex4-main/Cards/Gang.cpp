#include "Gang.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "vector"
static const string VAMPIRE_NAME;
static const string GOBLIN_NAME;
static const string DRAGON_NAME;

const std::string Gang::GANG_NAME = "Gang";

Gang::Gang(std::string name) : Card(name){}

Gang::Gang(Gang& gang1) : Card(gang1.getName())
{
    for(std::unique_ptr<BattleCard>& monster : (gang1.m_gangMonsters))
    {
        if((*monster).getName() == VAMPIRE_NAME){
            std::unique_ptr<BattleCard> tempVampire(new Vampire()); 
            m_gangMonsters.push_back(std::move(tempVampire));
        }
        else if((*monster).getName() == GOBLIN_NAME){
            std::unique_ptr<BattleCard> tempGoblin(new Goblin()); 
            m_gangMonsters.push_back(std::move(tempGoblin));
        }
        else if((*monster).getName() == DRAGON_NAME){
            std::unique_ptr<BattleCard> tempDragon(new Dragon()); 
            m_gangMonsters.push_back(std::move(tempDragon));
        }

    }
    
}

Gang& Gang::operator=(Gang& gang1)
{
    if(this == &gang1){
        return *this;
    }
    std::vector<std::unique_ptr<BattleCard>> tempVector;
    for(std::unique_ptr<BattleCard>& monster : (gang1.m_gangMonsters))
    {
        if((*monster).getName() == VAMPIRE_NAME){
            std::unique_ptr<BattleCard> tempVampire(new Vampire()); 
            tempVector.push_back(std::move(tempVampire));
        }
        else if((*monster).getName() == GOBLIN_NAME){
            std::unique_ptr<BattleCard> tempGoblin(new Goblin()); 
            tempVector.push_back(std::move(tempGoblin));
        }
        else if((*monster).getName() == DRAGON_NAME){
            std::unique_ptr<BattleCard> tempDragon(new Dragon()); 
            tempVector.push_back(std::move(tempDragon));
        }
    }  
    m_gangMonsters.clear();
    for(std::unique_ptr<BattleCard>& monster : (tempVector))
    {
        m_gangMonsters.push_back(std::move(monster));
    }
    tempVector.clear();
    return *this;
}


void Gang::addMonster(std::unique_ptr<BattleCard> newMonster){
    m_gangMonsters.push_back(std::move(newMonster));
    return;
}

void Gang::applyEncounter(Player& player) const{
    bool lost = false;
    for (const std::unique_ptr<BattleCard>& monster : m_gangMonsters){
        if(!lost && (player.getAttackStrength() < monster->getForce())){
            lost = true;
            player.setNeedToLose(true);
        }
        monster->setInGang(true);
        monster->applyEncounter(player);
    }
    if(!lost){
        player.levelUp();
        printWinBattle(player.getName(), GANG_NAME);
    }
    player.setNeedToLose(false);
}

void Gang::printCard(std::ostream& os) const {
    for(const std::unique_ptr<BattleCard>& monster : m_gangMonsters){
        monster->printCard(os);
    }
    return;
}

