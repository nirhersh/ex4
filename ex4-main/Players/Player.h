//
// Created by Nir Herscovici on 07/04/2022.
//
#ifndef EX4_Player_H
#define EX4_Player_H

#include <string>
#include <iostream>
class Player;
#include "../utilities.h"

using std::string;

class Player{
public:
    /*
    *
    * C'tor of the Player class
    * 
    * @param name - the name of the new player
    * @param maxHP - the maximum HP the player can have, default value is 100
    * @param force - the initial force of the player, defualt value is 5
    * @return 
    *        A new instance of a player
    */
    explicit Player(const string name, const int maxHP=100, const int force=5);

    /*
    *
    * Destructor of the Player class
    * 
    */
    virtual ~Player() = default;

    /*
    *
    * Copy C'tor of the Player class
    * 
    */
    Player(const Player& player) = default;

    Player& operator=(const Player& other) = default;

    /*
    * getters
    */
   string getName();
   int getCoins();

   /*
    * life to zero
    */
   void knockOut();


    /*
    *
    * a function that increments the level of the player by one, unless the player is at the maximum value, than it does nothing
    * 
    */
    void levelUp();
    
    /*
    *
    * a function that returns the current level of the player
    * @return 
    *       The current player level
    */
    int getLevel() const;

    
    /*
    *
    * a function that adds force to the player
    * 
    * @param forceBuff - the amount of force to add to the player
    * 
    */
    void buff(const int forceBuff);

    /*
    *
    * a function that adds HP to the player
    * 
    * @param hp - the amount of HP to add to the player
    * 
    */
    virtual void heal(const int hp);

    /*
    *
    * a function that subtracts HP from the player
    * 
    * @param damagePoints - the amount of HP to subtract from the player
    * 
    */
    void damage(const int damagePoints);

    /*
    *
    * a function that checks if the player has 0 HP
    * 
    * @return
    *       true if the player has 0 HP, otherwise false
    */
    bool isKnockedOut() const;

    
    /*
    *
    * a function that prints details of the player
    * 
    * @param coins - the out stream
    * 
    */
    virtual void print(std::ostream& os) const =0; 

    /*
    *
    * a function that adds coins to the player
    * 
    * @param coins - the amount of coins to add to the player
    * 
    */
    virtual void addCoins(const int coins);

    /*
    *
    * a function that subtracts coins from the player
    * 
    * @param payment - the amount of coins to subtract from the player
    * @return 
    *       true if the payment was successfull, false if the player didn't have enough money
    */
    bool pay(const int payment);
    
    /*
    *
    * a function that returns the current attack strength of the player: level + force
    * 
    * @return 
    *       the current attack strength of the player
    */
    virtual int getAttackStrength() const;

    void weaken();

private:

    friend std::ostream& operator<<(std::ostream& os, const Player& player1);

protected:
    string m_name;
    int m_level;
    int m_healthPoints;
    int m_coins;
    int m_maxHP;
    int m_force;
    static const int maxLevel = 10;
    static const int minLevel = 1;
    static const int minHealth = 0;
    static const int minCoins = 0;
    static const int defaultForce = 5;
    static const int defaultMaxHp = 100;
    static const int DEFUALT_COINS = 10;
};

#endif //EX4_Card_H