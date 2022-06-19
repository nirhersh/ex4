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
     *
     * @param name - The card's name
    */
    Card(std::string name);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player) const = 0;

    /*
    * Gets the card name
    *
    * @return - String that represents the card's name
    */
    std::string getName() const;

    Card(const Card&) = default;

    virtual ~Card() = default;

    Card& operator=(const Card& other) = default;

protected:
    /*
    * Printing operator for the Card class 
    *
    * @param os - The stream to print to
    * @param card - The card to print
    * 
    * @return - the stream written to
    */ 
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    /*
    * Print function for the print operator to use
    *
    * @param os - The stream to print to
    */
    virtual void printCard(std::ostream& os) const;

private:
    std::string m_name;
    static const char INVALID_CHAR = ' ';
    static const int NAME_MAX_SIZE = 15;
};


#endif //EX2_Card_H
