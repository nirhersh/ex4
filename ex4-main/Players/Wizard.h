

#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include "Player.h"

class Wizard : public Player {
public:
    Wizard(const string name, const int maxHP=100, const int force=5);
    void heal(const int hp) override;
    void print(std::ostream& os) const override;

};


#endif