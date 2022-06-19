#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include "Player.h"
#include <iostream>

class Rogue : public Player {
public:
    /*
    * C'tor of the Rogue class
    *
    * @param name - The player's name
    * @param maxHP - The players maximum HP, 100 by default 
    * @param force - The player's force, 5 by default
    * 
    */
    Rogue(const string name, const int maxHP=100, const int force=5);

    /*
    * A function that add's a given amount of coins to the player
    *
    * @param coins - the amount of coins to add to the player
    */ 
    void addCoins(const int coins) override;

    /*
    * Print function for the print operator to use
    *
    * @param os - The stream to print to
    */
    void print(std::ostream& os) const override;
private:
    static const int COINS_BONUS = 2;
    static const std::string ROGUE_TYPE;
};




#endif