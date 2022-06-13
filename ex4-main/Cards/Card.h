//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
#include "../Exception.h"
#include <ostream>

class Card {
public:
    /*
     * C'tor of Card class
    */
    Card(std::string name);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player) = 0;

    std::string getName() const;

    Card(const Card&) = default;

    virtual ~Card() = default;

    Card& operator=(const Card& other) = default;

protected:
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    virtual void printCard(std::ostream& os) const;

private:
    std::string m_name;

};


#endif //EX2_Card_H
