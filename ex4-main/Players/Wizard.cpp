#include "Wizard.h"

Wizard::Wizard(const string name, const int maxHP, const int force)
                : Player(name, maxHP, force) {}

void Wizard::heal(const int hp){
    if(hp <= 0){
        return;
    }
    if(hp + 2*m_healthPoints > m_maxHP){
        m_healthPoints = m_maxHP;
    }else{
        m_healthPoints += 2*hp;
    }
}

void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force, m_healthPoints, m_coins);
}