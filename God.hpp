// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   God.
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 20:16
 */

#ifndef GOD_HPP
#define GOD_HPP

#include "Character.h"
#include "Items"
#include "IDs.hpp"

class God : public Character
{
public:

    God( const std::string& _chname, long& _race, int& _level, Armor* armor, Weapon* weapon, Apparel* apparel )
    {
        SetCharStats( _chname, _race, _level, armor, weapon, apparel );
    }
    
    virtual ~God();

private:
  
    virtual void SetCharStats( const std::string& _chname, long& _race, int& _level, Armor* armor, Weapon* weapon, Apparel* apparel )
    {
         double def, atk, chmin_speed, chmax_speed;
                       
        this->_character._name = _chname;
        this->_character._id = IDs::race::GOD;
        this->_character._lvl = 1000000000;
        this->_character._hp = 10000000000;
        this->_character._mp = 10000000000;
        this->_character._exp = 1000000000;
        this->_character._dex = 1000000000;
        this->_character._stamina = 1000000000;
        this->_character._strenght = 1000000000;
        this->_character._inteligence = 1000000000;
                
        this->_character._curse = 0;
        this->_character._poison = 0;
        this->_character._bleeding = 0;
        
        atk = weapon->getAttackLevel() + this->_character._strenght - ( this->_character._curse + this->_character._poison + this->_character._bleeding );
        def = weapon->getDefenseLevel() + this->_character._strenght - ( this->_character._curse + this->_character._poison + this->_character._bleeding );
        
        this->_character._atacklevel = atk;
        this->_character._defenselevel = def;
        
        this->_character._armor_name = armor->getArmorName();
        this->_character._armor_defence = armor->getDefenselvl();
        this->_character._armor_weight = armor->getWeight();
        this->_character._armor_crafted = armor->getCraftedStatus();
        this->_character._armor_gem_attr = armor->getGemAttr();
        this->_character._armor_gem_bonus = armor->getGemBonus();
        
        this->_character._weapon_name = weapon->getName();
        this->_character._weapon_attack = weapon->getAttackLevel();
        this->_character._weapon_defence = weapon->getDefenseLevel();
        this->_character._weapon_weight = weapon->getWeight();
        this->_character._weapon_crafted = weapon->getCraftStatus();
        this->_character._weapon_gem_attr = weapon->getGemAttr();
        this->_character._weapon_gem_bonus = weapon->getGemBonus();
        this->_character._weapon_hand = weapon->getWeaponHand();
        
        chmax_speed = this->_character._dex + this->_character._stamina - ( armor->getWeight() + weapon->getWeight() );        
        chmin_speed = chmax_speed / 2; //REAVALIAR 
        
        this->_character._min_velocity =  chmin_speed;
        this->_character._max_velocity = chmax_speed;
    }
    
};


#endif /* GOD_HPP */

