#ifndef Pitfall_H
#define Pitfall_H

#include "Card.h"
#include "../PLayers/Rogue.h"
#include "../utilities.h"
#include <string>

class Pitfall : public Card{
public:
    /*
    * C'tor of Pitfall class
    */
    Pitfall(std::string name = PITFALL_NAME);

    Pitfall(const Pitfall&) = default;

    ~Pitfall() = default;

    Pitfall& operator=(const Pitfall&) = default;

    void applyEncounter(Player& player) override;

private:
    static const int PITFALL_DAMAGE = 10;
    static const std::string PITFALL_NAME;
};

#endif // Pitfall_H