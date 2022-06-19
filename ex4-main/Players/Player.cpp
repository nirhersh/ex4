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
m_level(MIN_LEVEL),
m_healthPoints(MIN_HEALTH),
m_coins(DEFUALT_COINS)
{
    if(maxHP > MIN_HEALTH ){
        m_healthPoints = maxHP;
        m_maxHP = maxHP;
    }
    else {
        m_healthPoints = DEFAULT_MAX_HP;
        m_maxHP = DEFAULT_MAX_HP;
    }

    if (force >= MIN_FORCE){
        m_force = force;
    }
    else {
        m_force = DEFAULT_FORCE;
    }
}

std::ostream& operator<<(std::ostream& os, const Player& player1)
{
    player1.print(os);
    return os;
}

void Player::levelUp(){
    if(m_level < MAX_LEVEL){
        ++m_level;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(const int forceBuff){
    if(forceBuff <= MIN_FORCE){
        return;
    }
    m_force += forceBuff;
}

void Player::heal(const int hp){
    if(hp <= MIN_HEALTH){
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
    if(m_healthPoints < MIN_HEALTH){
        m_healthPoints = MIN_HEALTH;
    }
}

bool Player::isKnockedOut() const{
    return MIN_HEALTH == m_healthPoints;
}

void Player::addCoins(const int coins){
    if(coins <= MIN_COINS){
        return;
    }
    m_coins += coins;
}

bool Player::pay(const int payment){
    if(payment < 0){
        return true;
    }
    if(m_coins - payment < MIN_COINS){
        return false;
    }else{
        m_coins -= payment;
    }
    return true;
}

int Player::getAttackStrength() const{
    return m_force + m_level;
}

string Player::getName() const
{
    return m_name;
}

int Player::getCoins() const
{
    return m_coins;
}

void Player::knockOut()
{
    m_healthPoints = MIN_HEALTH;
}

void Player::weaken(){
    if(m_force > MIN_FORCE){
        m_force--;
    }
}