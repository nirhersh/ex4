

#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include "Player.h"

class Fighter : public Player {
public:
    int getAttackStrength() const override;
    void print(std::ostream& os) override;


};


#endif