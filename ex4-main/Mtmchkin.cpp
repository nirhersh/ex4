#include "Mtmchkin.h"
#include "Exception.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>


Mtmchkin::Mtmchkin(const std::string fileName)
{
    m_numberOfRounds = 0;
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
                                && cardType != "Merchant" && cardType != "pitfall" && cardType != "Treasure"){
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
    string name;
    string playerType;
    bool startOver = false;
    bool playerAdded = false;
    for (int playerIndex = 0; playerIndex < numberOfPlayers; playerIndex++)
    {
        playerAdded = false;
        while(playerAdded == false)
        {
            startOver = false;
            printInsertPlayerMessage();
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
                break;
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
            bool shouldntGetHere = false;
            assert(shouldntGetHere);
        }

    }
}

void Mtmchkin::playRound(){
    if(isGameOver()){
            printGameEndMessage();
            printGameLeaderboard();
    }
    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    for(Player* currentPlayer : m_players){
        if(currentPlayer->isKnockedOut()){
            continue;
        }
        Card* currentCard = m_cards.front();
        printTurnStartMessage(currentPlayer->getName());
        currentCard->applyEncounter(*currentPlayer);
        m_cards.pop_front();
        m_cards.push_back(currentCard);
    }
}

bool Mtmchkin::isGameOver(){
    for(Player* player : m_players){
        if(!player->isKnockedOut()){
            m_isGameOver = false;
        }
        if(player->getLevel() == MAX_LEVEL){
            m_isGameOver = true;
            break;
        }
    }
    return m_isGameOver;
}

void Mtmchkin::printGameLeaderboard(){
    printLeaderBoardStartMessage();
    int ranking = 1;
    // initialize leaderboard
    for(Player* playerPtr : m_players){
        m_leaderBoard.push(playerPtr);
    }
    while(!m_leaderBoard.empty()){
        printPlayerLeaderBoard(ranking, (*m_leaderBoard.top()));
        m_leaderBoard.pop();
        ++ranking;
    }
}