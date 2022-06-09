#include "Card.h"
#include "utilities.h"
#include <iostream>
#include "Player.h"
#include "Mtmchkin.h"
using std::cout;
using std::endl;
using std::string;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
     m_cardsArray(new Card[numOfCards]),
     m_numOfCards(numOfCards),
     m_gameStatus(GameStatus::MidGame),
     m_currentCard(0),
     m_player(string(playerName))
{
     for (int i = 0; i < numOfCards; i++)
     {
          m_cardsArray[i] = cardsArray[i];
     }  
}

Mtmchkin::Mtmchkin(const Mtmchkin& other) :
     m_cardsArray(new Card[other.m_numOfCards]),
     m_numOfCards(other.m_numOfCards),
     m_gameStatus(other.m_gameStatus),
     m_currentCard(other.m_currentCard),
     m_player(other.m_player)
{
     for (int i = 0; i < other.m_numOfCards; i++)
     {
          m_cardsArray[i] = other.m_cardsArray[i];
     }  
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other){
     if(this == &other){
          return *this;
     }
     delete[] m_cardsArray;
     m_cardsArray = new Card[other.m_numOfCards];
     m_numOfCards = other.m_numOfCards;
     for(int i=0; i<m_numOfCards; i++){
          m_cardsArray[i] = other.m_cardsArray[i];
     }
     m_currentCard = other.m_currentCard;
     m_player = other.m_player;
     m_gameStatus = other.m_gameStatus;
     return *this;

}

Mtmchkin::~Mtmchkin(){
     delete[] m_cardsArray;
}


GameStatus Mtmchkin::getGameStatus() const{
     return m_gameStatus;
}

void Mtmchkin::playNextCard(){
     m_cardsArray[m_currentCard].printInfo();
     m_cardsArray[m_currentCard].applyEncounter(m_player);
     m_player.printInfo();
     ++m_currentCard;
     // if last card go back to the start of the card array
     if(m_currentCard >= m_numOfCards){
          m_currentCard = 0;
     }
     if(m_player.getLevel() == maxLevel){
          m_gameStatus = GameStatus::Win;
     }
     if(m_player.isKnockedOut()){
          m_gameStatus = GameStatus::Loss;
     }
}

bool Mtmchkin::isOver() const{
     if(m_gameStatus == GameStatus::Win || m_gameStatus == GameStatus::Loss){
          return true;
     }else{
          return false;
     }
}