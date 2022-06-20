#include "Merchant.h"

const std::string Merchant::MERCHANT_NAME = "Merchant";

Merchant::Merchant(std::string name) : Card(name){}

void Merchant::applyEncounter(Player& player) const{
    int playerChoice = INVALID_INPUT;
    int coinsPaid = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    while(playerChoice == INVALID_INPUT){
        playerChoice = getPlayersChoice();
    }
    switch(playerChoice){
        case BUY_HP:
            if(player.pay(HP_POTION_COST)){
                player.heal(HEAL);
                coinsPaid += HP_POTION_COST;
            }else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case BUY_FORCE:
            if(player.pay(FORCE_POTION_COST)){
                player.buff(FORCE_BUFF);
                coinsPaid += FORCE_POTION_COST;
            }else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
    }
    printMerchantSummary(std::cout, player.getName(), playerChoice, coinsPaid);
}

int Merchant::getPlayersChoice() const{
    int playerChoice = INVALID_INPUT;
    bool validInput = true;
    do{
        std::string inputString;
        std::getline(std::cin, inputString);
        if(inputString == ""){
            continue;
        }
        try{
            playerChoice = std::stoi(inputString);
        }catch(std::invalid_argument& e){
            printInvalidInput();
            validInput = false;
            continue;
        }
        
        if(playerChoice != LEAVE && playerChoice != BUY_HP && playerChoice != BUY_FORCE){
            printInvalidInput();
            validInput = false;
            playerChoice = INVALID_INPUT;
        }
        validInput = true;
    }while(!validInput);
    return playerChoice;
}