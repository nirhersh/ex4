#include "Fighter.h"



Fighter::Fighter(const string name, const int maxHP, const int force)
                : Player(name, maxHP, force) {}

int Fighter::getAttackStrength() const{
    return 2*m_force + m_level;
}

void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force, m_healthPoints, m_coins);
}