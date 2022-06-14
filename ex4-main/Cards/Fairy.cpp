#include "Fairy.h"

const std::string Fairy::FAIRY_NAME = "Fairy";

Fairy::Fairy(std::string name) : Card(name){}

void Fairy::applyEncounter(Player& player){
    bool isWizard = true;
    try{
        Wizard& wizard = dynamic_cast<Wizard&>(player);
        wizard.heal(HP_BOOST);
    }catch(std::bad_cast& e){
        isWizard = false;
    }
    printFairyMessage(isWizard);
}