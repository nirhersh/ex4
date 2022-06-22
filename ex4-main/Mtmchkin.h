#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <memory>
#include <map>
class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    Mtmchkin(const Mtmchkin&) = delete;

    Mtmchkin& operator=(const Mtmchkin&) = delete;
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver();
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::vector<std::unique_ptr<Player>> m_playersInGame;
    std::vector<std::unique_ptr<Player>> m_playersWon;
    std::vector<std::unique_ptr<Player>> m_playersDead;
    std::queue<std::unique_ptr<Card>> m_cards;
    bool m_isGameOver;
    int m_numberOfRounds;
    static const int MAX_LEVEL = 10;
    
    
        
};


#endif /* MTMCHKIN_H_ */
