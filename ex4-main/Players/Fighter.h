

#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include "Player.h"

class Fighter : public Player {
public:
    Fighter(const string name, const int maxHP=100, const int force=5);
    int getAttackStrength() const override;
    void print(std::ostream& os) const override;


};


#endif