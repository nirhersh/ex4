#include "Card.h"
using std::cout;
using std::endl;


Card::Card(std::string name){
    for(char c : name){
        if(!std::isalpha(c) || c == INVALID_CHAR){
            throw InvalidCardName(name);
        }
    }
    if(name.size() > NAME_MAX_SIZE){
        throw InvalidCardSize();
    }
    m_name = name;
}

std::string Card::getName() const{
    return m_name;
}

void Card::printCard(std::ostream& os) const{
    return;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    printCardDetails(os, card.getName());
    card.printCard(os);
    printEndOfCardDetails(os);
    return os;
}

