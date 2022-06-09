

#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include "Player.h"

class Wizard : public Player {
public:
    void heal(const int hp) override;
    void print(std::ostream& os) override;

};


#endif