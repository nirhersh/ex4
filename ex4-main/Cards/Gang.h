#ifndef GANG_H
#define GANG_H

#include "Card.h"
#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"
#include <vector>
#include <memory>

class Gang : public Card{
public:
    Gang(std::string name = GANG_NAME);

    ~Gang() = default;

    Gang(const Gang&) = delete;

    Gang& operator=(const Gang&) = delete;

    void addMonster(std::unique_ptr<BattleCard> newMonster);

    void applyEncounter(Player& player) const override;

    /*
    * Print function for thE Battle Card
    *
    * @param os - The stream to print to
    */
    void printCard(std::ostream& os) const override;

private:
    std::vector<std::unique_ptr<BattleCard>> m_gangMonsters;
    static const int INITIAL_SIZE = 0;
    static const std::string GANG_NAME;
};

#endif // GANG_H