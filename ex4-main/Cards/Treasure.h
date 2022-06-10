#ifndef Treasure_H
#define Treasure_H

#include "Card.h"
#include "../utilities.h"
#include <string>

class Treasure : public Card{
public:
    /*
    * C'tor of Treasure class
    */
    Treasure(std::string name = TREASURE_NAME);

    Treasure(const Treasure&) = default;

    ~Treasure() = default;

    Treasure& operator=(const Treasure&) = default;

    void applyEncounter(Player& player) override;

private:
    static const int TREASURE_COINS = 10;
    static const std::string TREASURE_NAME;
};

#endif // Treasure_H