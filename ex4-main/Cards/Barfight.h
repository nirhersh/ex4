#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"
#include "../utilities.h"
#include <string>

class Barfight : public Card{
public:
    /*
    * C'tor of Barfight class
    */
    Barfight(std::string name = BARFIGHT_NAME, int damage = HP_LOSS);

    Barfight(const Barfight&) = default;

    ~Barfight() = default;

    Barfight& operator=(const Barfight&) = default;

    /*
    * A function that changes a given player according to the encounter with a Barfight card
    *
    * @param player - The player.
    */
    void applyEncounter(Player& player) const override;

private:
    int m_damage;
    static const int HP_LOSS = 10;
    static const std::string BARFIGHT_NAME;
};

#endif // BARFIGHT_H