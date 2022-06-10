//
// Implementation of Player class
//

#include "Player.h"
#include "Rogue.h"
#include "Fighter.h"
#include "Wizard.h"
#include "../utilities.h"

using std::string;
using std::cout;

Player::Player(const string name, const int maxHP, const int force) :
m_name(name),
m_level(minLevel),
m_healthPoints(minHealth),
m_coins(minCoins)
{
    if(maxHP > 0 ){
        m_healthPoints = maxHP;
        m_maxHP = maxHP;
    }
    else {
        m_healthPoints = defaultMaxHp;
        m_maxHP = defaultMaxHp;
    }

    if (force >= 0){
        m_force = force;
    }
    else {
        m_force = defaultForce;
    }
}

//  void Player::printInfo() const{
//      printPlayerDetails(m_name.c_str(), m_level, m_force, m_healthPoints, m_coins);
//  }
    std::ostream& operator<<(std::ostream& os, const Player& player1)
    {
        player1.print(os);
        return os;
    }


void Player::levelUp(){
    if(m_level < maxLevel){
        ++m_level;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(const int forceBuff){
    if(forceBuff <= 0){
        return;
    }
    m_force += forceBuff;
}

void Player::heal(const int hp){
    if(hp <= 0){
        return;
    }
    if(hp + m_healthPoints > m_maxHP){
        m_healthPoints = m_maxHP;
    }else{
        m_healthPoints += hp;
    }
}

void Player::damage(const int damagePoints){
    if(damagePoints <= 0){
        return;
    }
    m_healthPoints -= damagePoints;
    if(m_healthPoints < minHealth){
        m_healthPoints = minHealth;
    }
}

bool Player::isKnockedOut() const{
    return minHealth == m_healthPoints;
}

void Player::addCoins(const int coins){
    if(coins <= 0){
        return;
    }
    m_coins += coins;
}

bool Player::pay(const int payment){
    if(payment < 0){
        return true;
    }
    if(m_coins - payment < minCoins){
        return false;
    }else{
        m_coins -= payment;
    }
    return true;
}

int Player::getAttackStrength() const{
    return m_force + m_level;
}

string Player::getName()
{
    return m_name;
}

int Player::getCoins()
{
    return m_coins;
}

void Player::knockOut()
{
    m_healthPoints = 0;
}