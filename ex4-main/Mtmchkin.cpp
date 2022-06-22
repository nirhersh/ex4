#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

static void cardInitialization(std::string fileName, std::queue<std::unique_ptr<Card>>& m_cards);
static int numberOfPlayersInitialization();
static void playerInitialization(std::vector<std::unique_ptr<Player>>& m_players);
static void addDragonCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addPitfallCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addBarfightCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addFairyCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addGoblinCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addMerchantCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addTreasureCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addVampireCard(std::queue<std::unique_ptr<Card>>& cardsQueue);
static void addGangCard(std::queue<std::unique_ptr<Card>>& cardsQueue, std::fstream& cardsDeckFile, int& line);

enum CARD_TYPES{
    cardBarfight,
    cardFairy,
    cardDragon,
    cardGoblin,
    cardMerchant,
    cardPitfall,
    cardTreasure,
    cardVampire,
    cardGang,
    cardEndGang };

    static const int MAX_NAME_SIZE = 15;

enum PLAYER_TYPES{
    playereFighter,
    playerWizard,
    playerRogue};

static std::map<std::string, CARD_TYPES> CARDS;
static std::map<std::string, PLAYER_TYPES> PLAYERS;

static void initializeCardMap()
{
    CARDS["Barfight"] = cardBarfight;
    CARDS["Dragon"] = cardDragon;
    CARDS["Fairy"] = cardFairy;
    CARDS["Goblin"] = cardGoblin;
    CARDS["Merchant"] = cardMerchant;
    CARDS["Pitfall"] = cardPitfall;
    CARDS["Treasure"] = cardTreasure;
    CARDS["Vampire"] = cardVampire;
    CARDS["Gang"] = cardGang;
    CARDS["EndGang"] = cardEndGang;
}

static void initializePlayerMap()
{
    PLAYERS["Fighter"] = playereFighter;
    PLAYERS["Rogue"] = playerRogue;
    PLAYERS["Wizard"] = playerWizard;
}


Mtmchkin::Mtmchkin(const std::string fileName)
{
    initializeCardMap();
    initializePlayerMap();
    printStartGameMessage();
    m_numberOfRounds = 0;
    m_isGameOver = false;
    cardInitialization(fileName, m_cards);
    playerInitialization(m_playersInGame);
    
}

static void cardInitialization(std::string fileName, std::queue<std::unique_ptr<Card>>& m_cards)
{
    std::fstream cardsDeckFile;
    cardsDeckFile.open(fileName, std::ios::in);
    if(!cardsDeckFile.is_open()){
        throw DeckFileNotFound();
    }
    int line = 1; 
    string cardType;
    while(std::getline(cardsDeckFile, cardType))
    {
        if(CARDS.count(cardType) == 0){
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
        }
        line++;
        switch (CARDS[cardType])
        {
        case cardDragon:
            addDragonCard(m_cards);
            break;
        case cardBarfight:
            addBarfightCard(m_cards);
            break;
        case cardFairy:
            addFairyCard(m_cards);
            break;  
        case cardGoblin:
            addGoblinCard(m_cards);
            break;
        case cardMerchant:
            addMerchantCard(m_cards);
            break;
        case cardVampire:
            addVampireCard(m_cards);
            break;
        case cardTreasure:
            addTreasureCard(m_cards);
            break;
        case cardPitfall:
            addPitfallCard(m_cards);
            break;
        case cardGang:
            addGangCard(m_cards, cardsDeckFile, line);
            break;
        case cardEndGang:{
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
            break;
        }
        default:
            break;
        }
    }
    if(line < 5){
        cardsDeckFile.close();
        throw DeckFileInvalidSize();
    }
    cardsDeckFile.close();
}

static int numberOfPlayersInitialization()
{
    printEnterTeamSizeMessage();
    bool validInput = false;
    int numberOfPlayers;
    std::string inputString;
    while(validInput == false){
        getline(std::cin, inputString);
        try{
            numberOfPlayers = std::stoi(inputString);
        }catch(std::invalid_argument& e){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            validInput = false;
            continue;
        }
        if(numberOfPlayers < 2 || numberOfPlayers > 6){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            validInput = false;
            continue;
        }
        validInput = true;
    }
    return numberOfPlayers;
}

static void playerInitialization(std::vector<std::unique_ptr<Player>>& m_playersInGame)
{
    int numberOfPlayers = numberOfPlayersInitialization();
    string name, playerType;
    bool startOver = false, playerAdded = false;
    for (int playerIndex = 0; playerIndex < numberOfPlayers; playerIndex++)
    {
        printInsertPlayerMessage();
        playerAdded = false;
        while(playerAdded == false)
        {
            startOver = false;
            std::cin >> name;
            std::cin >> playerType;
            if(name.size() > MAX_NAME_SIZE){
                printInvalidName();
                continue;
            }
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
            if(PLAYERS.count(playerType) == 0){
                printInvalidClass();
                continue;
            }
            //now we know the input is valid
            switch (PLAYERS[playerType])
            {
                case playerRogue:{
                    std::unique_ptr<Player> player(new Rogue(name));
                    m_playersInGame.push_back(std::move(player));
                    playerAdded = true;
                    break;
                }
                case playerWizard:{
                    std::unique_ptr<Player> player(new Wizard(name));
                    m_playersInGame.push_back(std::move(player));
                    playerAdded = true;
                    break;
                }
                case playereFighter: {
                    std::unique_ptr<Player> player(new Fighter(name));
                    m_playersInGame.push_back(std::move(player));
                    playerAdded = true;
                    break;
                }
                // bool shouldntGetHere = false;
                // assert(shouldntGetHere);
            }
        }
    
    }
}

void Mtmchkin::playRound(){
    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    for(std::unique_ptr<Player>& currentPlayer : m_playersInGame){
        if(currentPlayer == nullptr){
            continue;
        }
        printTurnStartMessage(currentPlayer->getName());
        m_cards.front()->applyEncounter(*currentPlayer);
        if(currentPlayer->isKnockedOut()){
            m_playersDead.insert(m_playersDead.begin(), std::move(currentPlayer));
        }else if(currentPlayer->getLevel() == MAX_LEVEL){
            m_playersWon.push_back(std::move(currentPlayer));
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
    m_isGameOver = (m_playersInGame.size() == (m_playersDead.size() + m_playersWon.size()));
    return m_isGameOver;
}

void Mtmchkin::printLeaderBoard() const{
    int ranking = 1;
    printLeaderBoardStartMessage();
    for(const std::unique_ptr<Player>& player : m_playersWon){
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
    for(const std::unique_ptr<Player>& player : m_playersInGame){
        if(player == nullptr){
            continue;
        }
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
    for(const std::unique_ptr<Player>& player : m_playersDead){
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}

static void addDragonCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Dragon());
    cardsQueue.push(std::move(card));
}

static void addPitfallCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Pitfall());
    cardsQueue.push(std::move(card));
}

static void addBarfightCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Barfight());
    cardsQueue.push(std::move(card));
}

static void addFairyCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Fairy());
    cardsQueue.push(std::move(card));
}

static void addGoblinCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Goblin());
    cardsQueue.push(std::move(card));
}

static void addMerchantCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Merchant());
    cardsQueue.push(std::move(card));
}

static void addTreasureCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Treasure());
    cardsQueue.push(std::move(card));
}

static void addVampireCard(std::queue<std::unique_ptr<Card>>& cardsQueue)
{
    std::unique_ptr<Card> card(new Vampire());
    cardsQueue.push(std::move(card));
}

static void addGangCard(std::queue<std::unique_ptr<Card>>& cardsQueue, std::fstream& cardsDeckFile, int& line)
{
    Gang* gangCard = new Gang();
    string cardType;
    while(std::getline(cardsDeckFile, cardType))
    {
        if(CARDS.count(cardType) == 0){
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
        }
        line++;
        switch (CARDS[cardType])
        {
        case cardDragon:{
            std::unique_ptr<BattleCard> dragonCard(new Dragon());
            gangCard->addMonster(std::move(dragonCard));
            break;
        }
        case cardGoblin: {
            std::unique_ptr<BattleCard> goblinCard(new Goblin());
            gangCard->addMonster(std::move(goblinCard));
            break;
        }

        case cardVampire:{
            std::unique_ptr<BattleCard> vampireCard(new Vampire());
            gangCard->addMonster(std::move(vampireCard));
            break;
        }
        case cardGang:{
            cardsDeckFile.close();
            throw DeckFileFormatError(line);
            break;
        }
        case cardEndGang:{
            std::unique_ptr<Card> gangPtr = static_cast<std::unique_ptr<Card>>(gangCard);
            cardsQueue.push(std::move(gangPtr));
            return;
        }
        default:
            break;
        } 
    }
    cardsDeckFile.close();
    throw DeckFileFormatError(line);
}