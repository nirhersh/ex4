#include "Rogue.h"

const std::string Rogue::ROGUE_TYPE = "Rogue";

Rogue::Rogue(const string name, const int maxHP, const int force)
                : Player(name, maxHP, force) {}

void Rogue::addCoins(const int coins) 
    {
        if(coins <= MIN_COINS){
            return;
        }
        m_coins += COINS_BONUS*coins;
    }

void Rogue::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, ROGUE_TYPE, m_level, m_force, m_healthPoints, m_coins);
}