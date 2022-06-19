

#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include "Player.h"

class Fighter : public Player {
public:
    /*
    * C'tor of the Fighter class
    *
    * @param name - The player's name
    * @param maxHP - The players maximum HP, 100 by default 
    * @param force - The player's force, 5 by default
    * 
    */ 
    Fighter(const string name, const int maxHP=100, const int force=5);

    /*
    * A function that returns the attack strength of the player which is level + force
    *
    * @return - The player's attack strength
    */  
    int getAttackStrength() const override;

    /*
    * Print function for the print operator to use
    *
    * @param os - The stream to print to
    */
    void print(std::ostream& os) const override;

private:
    static const int FORCE_BONUS = 2;
    static const std::string FIGHTER_TYPE;
};


#endif