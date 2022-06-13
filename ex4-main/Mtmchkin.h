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
#include "Cards/vampire.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include <vector>
#include <queue>
#include <deque>
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

    void printGameLeaderboard();

    class ComparePlayers{
    public:
        bool operator()(const Player* player1, const Player* player2) const{
            return (*player1) < (*player2);
        }
    };

private:
    std::vector<Player*> m_players;
    std::deque<Card*> m_cards;
    std::priority_queue<Player*, std::vector<Player*>, ComparePlayers> m_leaderBoard;
    bool m_isGameOver;
    int m_numberOfRounds;
    static const int MAX_LEVEL = 10;
};

#endif /* MTMCHKIN_H_ */
