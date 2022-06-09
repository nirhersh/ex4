#include "Card.h"
#include "utilities.h"
#include <iostream>
#include "Player.h"
using std::cout;
using std::endl;


Card::Card(CardType type, const CardStats& stats){
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
    if(m_effect == CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal); 
        }
    }
    if(m_effect == CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff); 
        }
    } 
    if(m_effect == CardType::Battle)
    {
        if(m_stats.force > player.getAttackStrength())
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        } else {
            player.addCoins(m_stats.loot);
            player.levelUp();
            printBattleResult(true);
        } 
    }  

}

void Card::printInfo() const
{
    if(this->m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if(this->m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
    }
    else if(this->m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else
    {
        printTreasureCardInfo(m_stats);
    }
}

