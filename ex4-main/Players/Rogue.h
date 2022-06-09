#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include "Player.h"
#include <iostream>

class Rogue : public Player {
public:
    void addCoins(const int coins) override;
    void print(std::ostream& os) override;

};




#endif