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
            // while (m_cards.size() > 0){
            //     delete m_cards.back();
            //     m_cards.pop_back();
            // }
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
            }
        line++;
        if(cardType == "Fairy"){
            std::unique_ptr<Card> card(new Fairy());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Goblin"){
            std::unique_ptr<Card> card(new Goblin());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Vampire"){
            std::unique_ptr<Card> card(new Vampire());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Barfight"){
            std::unique_ptr<Card> card(new Barfight());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Dragon"){
            std::unique_ptr<Card> card(new Dragon());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Merchant"){
            std::unique_ptr<Card> card(new Merchant());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Pitfall"){
            std::unique_ptr<Card> card(new Pitfall());
            m_cards.push(std::move(card));
            continue;
        }
        if(cardType == "Treasure"){
            std::unique_ptr<Card> card(new Treasure());
            m_cards.push(std::move(card));
            continue;
        }
    }
    if(line < 5){
        // while (m_cards.size() > 0){
        //     delete m_cards.back();
        //     m_cards.pop_back();
        // }
        cardsDeckFile.close();
        throw DeckFileInvalidSize();
    }
    cardsDeckFile.close();
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
                m_players.push_back(std::shared_ptr<Player>(new Rogue(name)));
                playerAdded = true;
                continue;
            }
            if(playerType == "Fighter"){
                m_players.push_back(std::shared_ptr<Player>(new Fighter(name)));
                playerAdded = true;
                continue;
            }
            if(playerType == "Wizard"){
                m_players.push_back(std::shared_ptr<Player>(new Wizard(name)));
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
    for(std::shared_ptr<Player> currentPlayer : m_players){
        if(currentPlayer->isKnockedOut() || currentPlayer->getLevel() == MAX_LEVEL){
            continue;
        }
        printTurnStartMessage(currentPlayer->getName());
        m_cards.front()->applyEncounter(*currentPlayer);
        fillLeaderboard();
        if(currentPlayer->isKnockedOut() || currentPlayer->getLevel() == MAX_LEVEL){
            updateLeaderboard(currentPlayer);
        }
        if(isGameOver()){
            printGameEndMessage();
        }
        std::unique_ptr<Card> temp = std::move(m_cards.front());
        m_cards.pop();
        m_cards.push(std::move(temp));
    }
}

bool Mtmchkin::isGameOver(){
    m_isGameOver = true;
    for(std::shared_ptr<Player> player : m_players){
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
    for(std::shared_ptr<Player> player : m_leaderboard){
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
}

void Mtmchkin::updateLeaderboard(std::shared_ptr<Player> player){
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
    for(std::shared_ptr<Player> player : m_players){
        if(!player->isKnockedOut() && player->getLevel() != MAX_LEVEL){
            m_leaderboard[fillIndex] = player;
            fillIndex++;
        }
    }
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}

// Mtmchkin::~Mtmchkin()
// {
//     while (m_players.size() > 0)
//     {
//         delete m_players.back();
//         m_players.pop_back();
//     }

//     while (m_cards.size() > 0)
//     {
//         delete m_cards.back();
//         m_cards.pop_back();
//     }
// }
