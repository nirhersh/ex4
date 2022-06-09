#include "Fighter.h"

int Fighter::getAttackStrength() const{
    return 2*m_force + m_level;
}

void Fighter::print(std::ostream& os) 
{
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force, m_healthPoints, m_coins);
}