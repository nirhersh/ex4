//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    /*
     *  Copy C'tor of the Mtmchkin class:
     *
     *  @param: Mtmchkin& - the Mtmchkin object to copy
     *      
     */
    Mtmchkin(const Mtmchkin&);

    /*
     *  Assignment operator of the Mtmchkin class
     *
     *  @param Mtmchkin& - the Mtmchkin object to assign to the object
     *  @return
     *          reference to the assigned object
     */
    Mtmchkin& operator=(const Mtmchkin&);

    /*
     *
     *  D'tor of the Mtmchkin class
     * 
     */
    ~Mtmchkin();


private:
    Card* m_cardsArray;
    int m_numOfCards;
    GameStatus m_gameStatus;
    int m_currentCard;
    Player m_player;
    static const int maxLevel = 10;
    



};


#endif //EX2_GAME_H
