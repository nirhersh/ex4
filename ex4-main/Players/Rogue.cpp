#include "Rogue.h"

void Rogue::addCoins(const int coins) 
    {
        if(coins <= 0){
            return;
        }
        m_coins += 2*coins;
    }

void Rogue::print(std::ostream& os) 
{
    printPlayerDetails(os, m_name, "Rogue", m_level, m_force, m_healthPoints, m_coins);
}