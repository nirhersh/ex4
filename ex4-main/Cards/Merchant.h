#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"
#include "../utilities.h"
#include <string>

class Merchant : public Card{
public:
    /*
    * C'tor of merchant class
    */
    Merchant(std::string name = MERCHANT_NAME);

    Merchant(const Merchant&) = default;

    ~Merchant() = default;

    Merchant& operator=(const Merchant&) = default;

    /*
     * Handling the player's applyEncounter with the Merchant card:
     *
     * @param player - The player.
    */
    void applyEncounter(Player& player) const override;


private:
    static const int HP_POTION_COST = 5;
    static const int HEAL = 1;
    static const int FORCE_POTION_COST = 10;
    static const int FORCE_BUFF = 1;
    static const std::string MERCHANT_NAME;
    static const int LEAVE = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    static const int INVALID_INPUT = -1;
    int getPlayersChoice() const;
};

#endif // MERCHANT_H