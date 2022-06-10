#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include "Player.h"
#include <iostream>

class Rogue : public Player {
public:
    Rogue(const string name, const int maxHP=100, const int force=5);
    void addCoins(const int coins) override;
    void print(std::ostream& os) const override;

};




#endif