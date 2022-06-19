#include "Fighter.h"

const std::string Fighter::FIGHTER_TYPE = "Fighter";

Fighter::Fighter(const string name, const int maxHP, const int force)
                : Player(name, maxHP, force) {}

int Fighter::getAttackStrength() const{
    return FORCE_BONUS*m_force + m_level;
}

void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, FIGHTER_TYPE, m_level, m_force, m_healthPoints, m_coins);
}