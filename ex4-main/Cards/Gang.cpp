#include "Gang.h"

const std::string Gang::GANG_NAME = "Gang";

Gang::Gang(std::string name) : Card(name){}

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
    // for(const std::unique_ptr<BattleCard>& monster : m_gangMonsters){
    //     monster->printCard(os);
    // }
    return;
}

