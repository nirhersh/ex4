#include "Wizard.h"

const std::string Wizard::WIZARD_TYPE = "Wizard";

Wizard::Wizard(const string name, const int maxHP, const int force)
                : Player(name, maxHP, force) {}

void Wizard::heal(const int hp){
    if(hp <= MIN_HEALTH){
        return;
    }
    if(HEAL_BONUS*hp + m_healthPoints > m_maxHP){
        m_healthPoints = m_maxHP;
    }else{
        m_healthPoints += HEAL_BONUS*hp;
    }
}

void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os, m_name, WIZARD_TYPE, m_level, m_force, m_healthPoints, m_coins);
}