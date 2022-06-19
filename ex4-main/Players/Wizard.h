

#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include "Player.h"

class Wizard : public Player {
public:
    /*
    * C'tor of the Wizard class
    *
    * @param name - The player's name
    * @param maxHP - The players maximum HP, 100 by default 
    * @param force - The player's force, 5 by default
    * 
    */
    Wizard(const string name, const int maxHP=100, const int force=5);

    /*
    * a function that adds HP to the HP of the Wizard
    *
    * @param hp - The amount of HP to add
    */ 
    void heal(const int hp) override;

    /*
    * Print function for the print operator to use
    *
    * @param os - The stream to print to
    */
    void print(std::ostream& os) const override;

private:
    static const int HEAL_BONUS = 2;
    static const std::string WIZARD_TYPE;
};


#endif