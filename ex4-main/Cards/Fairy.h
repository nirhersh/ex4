#ifndef Fairy_H
#define Fairy_H

#include "Card.h"
#include "../Players/Wizard.h"
#include "../utilities.h"
#include <string>

class Fairy : public Card{
public:
    /*
    * C'tor of Fairy class
    */
    Fairy(std::string name = FAIRY_NAME, int heal = HP_BOOST);

    Fairy(const Fairy&) = default;

    ~Fairy() = default;

    Fairy& operator=(const Fairy&) = default;

    /*
     * Handling the player's applyEncounter with the Fairy card:
     *
     * @param player - The player.
    */
    void applyEncounter(Player& player) override;

private:
    int m_heal;
    static const int HP_BOOST = 10;
    static const std::string FAIRY_NAME;
};

#endif // Fairy_H