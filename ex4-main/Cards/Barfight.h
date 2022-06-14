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
    Barfight(std::string name = BARFIGHT_NAME);

    Barfight(const Barfight&) = default;

    ~Barfight() = default;

    Barfight& operator=(const Barfight&) = default;

    void applyEncounter(Player& player) override;

private:
    int m_damage;
    static const int HP_LOSS = 10;
    static const std::string BARFIGHT_NAME;
};

#endif // BARFIGHT_H