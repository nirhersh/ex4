#include "Fairy.h"

const std::string Fairy::FAIRY_NAME = "Fairy";

Fairy::Fairy(std::string name, int heal) : Card(name), m_heal(heal){}

void Fairy::applyEncounter(Player& player){
    bool isWizard = true;
    try{
        Wizard& wizard = dynamic_cast<Wizard&>(player);
        wizard.heal(m_heal);
    }catch(std::bad_cast& e){
        isWizard = false;
    }
    printFairyMessage(isWizard);
}
