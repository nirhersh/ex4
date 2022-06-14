#include "../Mtmchkin.h"

int main(){
    static const int FAIL = -1;
    static const int SUCCESS = 1;
    static const int MAX_ROUNDS = 100;
    std::string filePath = "deck.txt";
    try{
        Mtmchkin game = Mtmchkin(filePath);
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_ROUNDS){
            game.playRound();
            game.printLeaderBoard();
        }
    }catch(DeckFileError& e){
        std::cout << e.what() << std::endl;
        return FAIL;
    }
    return SUCCESS;
}
