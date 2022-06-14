#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>


Mtmchkin::Mtmchkin(const std::string fileName)
{
    m_numberOfRounds = 0;
    m_playersAtMaxLevel = 0;
    m_playersDead = 0;
    m_isGameOver = false;
    std::fstream cardsDeckFile;
    cardsDeckFile.open(fileName, std::ios::in);
    if(!cardsDeckFile.is_open()){
        throw DeckFileNotFound();
    }
    int line = 1; // should I start countind the lines from 1 or 0?
    string cardType;
    while(std::getline(cardsDeckFile, cardType))
    {
        // Should instead keep a set of strings with the names and use the function find() to see if the name from the file is in the set, and also a switch case might be nicer than all of the 
        // if elses, same with the players types :)
        if (cardType != "Fairy" && cardType != "Goblin" && cardType != "Vampire" && cardType != "Barfight" && cardType != "Dragon" 
                                && cardType != "Merchant" && cardType != "Pitfall" && cardType != "Treasure"){
            while(m_cards.size() > 0)
            {
                m_cards.pop_front(); //clean storage
            }
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
            }
        line++;
        if(cardType == "Fairy"){
            m_cards.push_back(new Fairy());
            continue;
        }
        if(cardType == "Goblin"){
            m_cards.push_back(new Goblin());
            continue;
        }
        if(cardType == "Vampire"){
            m_cards.push_back(new Vampire());
            continue;
        }
        if(cardType == "Barfight"){
            m_cards.push_back(new Barfight());
            continue;
        }
        if(cardType == "Dragon"){
            m_cards.push_back(new Dragon());
            continue;
        }
        if(cardType == "Merchant"){
            m_cards.push_back(new Merchant());
            continue;
        }
        if(cardType == "Pitfall"){
            m_cards.push_back(new Pitfall());
            continue;
        }
        if(cardType == "Treasure"){
            m_cards.push_back(new Treasure());
            continue;
        }
    }
    if(line < 5){
        while (m_cards.size() > 0){
            m_cards.pop_front();
        }
        cardsDeckFile.close();
        throw DeckFileInvalidSize();
    }
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int numberOfPlayers;
    std::cin >> numberOfPlayers;
    while (numberOfPlayers < 2 || numberOfPlayers > 6){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> numberOfPlayers;
    }
    for(int i=0; i<numberOfPlayers; i++){
        m_leaderboard.push_back(nullptr);
    }
    string name;
    string playerType;
    bool startOver = false;
    bool playerAdded = false;
    for (int playerIndex = 0; playerIndex < numberOfPlayers; playerIndex++)
    {
        printInsertPlayerMessage();
        playerAdded = false;
        while(playerAdded == false)
        {
            startOver = false;
            
            std::cin >> name;
            std::cin >> playerType;
            for (char c : name)
            {
                if(!isalpha(c)){
                    printInvalidName();
                    startOver = true;
                    break;
                }
            }
            if(startOver){
                continue;
            }
            if(playerType != "Fighter" && playerType != "Rogue" && playerType != "Wizard"){
                printInvalidClass();
                continue;
            }
            //now we know the input is valid

            if(playerType == "Rogue"){
                m_players.push_back(new Rogue(name));
                playerAdded = true;
                continue;
            }
            if(playerType == "Fighter"){
                m_players.push_back(new Fighter(name));
                playerAdded = true;
                continue;
            }
            if(playerType == "Wizard"){
                m_players.push_back(new Wizard(name));
                playerAdded = true;
                continue;
            }
            // bool shouldntGetHere = false;
            // assert(shouldntGetHere);
        }

    }
}

void Mtmchkin::playRound(){
    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    for(Player* currentPlayer : m_players){
        if(currentPlayer->isKnockedOut() || currentPlayer->getLevel() == MAX_LEVEL){
            continue;
        }
        Card* currentCard = m_cards.front();
        printTurnStartMessage(currentPlayer->getName());
        currentCard->applyEncounter(*currentPlayer);
        fillLeaderboard();
        if(currentPlayer->isKnockedOut() || currentPlayer->getLevel() == MAX_LEVEL){
            updateLeaderboard(currentPlayer);
        }
        if(isGameOver()){
            printGameEndMessage();
        }
        m_cards.pop_front();
        m_cards.push_back(currentCard);
    }
}

bool Mtmchkin::isGameOver(){
    m_isGameOver = true;
    for(Player* player : m_players){
        if((!player->isKnockedOut()) && (player->getLevel() != MAX_LEVEL)){
            m_isGameOver = false;
            break;
        }
    }
    return m_isGameOver;
}

void Mtmchkin::printLeaderBoard() const{
    int ranking = 1;
    printLeaderBoardStartMessage();
    for(Player* player : m_leaderboard){
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
}

void Mtmchkin::updateLeaderboard(Player* player){
    if(player->isKnockedOut()){
        m_leaderboard[m_leaderboard.size()-1-m_playersDead] = player;
        m_playersDead++;
    }else{
        m_leaderboard[m_playersAtMaxLevel] = player;
        m_playersAtMaxLevel++;
    }
}

void Mtmchkin::fillLeaderboard(){
    int fillIndex = m_playersAtMaxLevel;
    for(Player* player : m_players){
        if(!player->isKnockedOut() && player->getLevel() != MAX_LEVEL){
            m_leaderboard[fillIndex] = player;
            fillIndex++;
        }
    }
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}
