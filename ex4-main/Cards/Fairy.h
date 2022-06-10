#ifndef Fairy_H
#define Fairy_H

#include "Card.h"
#include "Wizard.h"
#include "utilities.h"
#include <string>

class Fairy : public Card{
public:
    /*
    * C'tor of Fairy class
    */
    Fairy(std::string name = FAIRY_NAME);

    Fairy(const Fairy&) = default;

    ~Fairy() = default;

    Fairy& operator=(const Fairy&) = default;

    void applyEncounter(Player& player) override;

private:
    static const int HP_BOOST = 10;
    static const std::string FAIRY_NAME;
};

#endif // Fairy_H