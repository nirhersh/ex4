#include "Merchant.h"

const std::string Merchant::MERCHANT_NAME = "Merchant";

Merchant::Merchant(std::string name) : Card(name){}

void Merchant::applyEncounter(Player& player){
    int playerChoice = 0;
    bool validInput = true;
    int coinsPaid = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    do{
        std::cin >> playerChoice;
        if(playerChoice != LEAVE && playerChoice != BUY_HP && playerChoice != BUY_FORCE){
            printInvalidInput();
            validInput = false;
        }
    }while(!validInput);

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