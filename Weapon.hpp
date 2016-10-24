/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weappon.hpp
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 15:24
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

#include "Gem.hpp"
#include "IDs.hpp"

class Weapon {
public:
   Weapon( const std::string& wp_name, long& weapon_id, long& hand_id,
            const double& atk_lvl, const double& def_lvl, const double& weight, bool crafted, Gem* gem ); 
    virtual ~Weapon();
    
    std::string getName() const { return this->weapon._name; }
    long getWeaponHand() const { return this->weapon._weapon_hand; }
    double getAttackLevel() const { return this->weapon._attack_lvl; }
    double getDefenseLevel() const { return this->weapon._defense_lvl; }
    double getWeight() const { return this->weapon._weapon_weight; }
    bool getCraftStatus() const { return this->weapon._crafted; }
    std::string getGemAttr() const { return this->weapon._gem_attr; }
    double getGemBonus() const { this->weapon._gem_bonus; }
    
private:
    
    struct weapon_attr
    {
        std::string _name;
        long _weapon_id;
        long _weapon_hand;
        double _attack_lvl;
        double _defense_lvl;
        double _weapon_weight;
        std::string _gem_attr;
        bool _crafted;
        double _gem_bonus;
    } weapon;
    
    void SetAttributes( const std::string& wp_name, long& weapon_id, long hand_id, 
        const double& atk_lvl, const double& def_lvl, const double& weight, bool crafted, Gem* gem );
};

#endif /* WEAPPON_HPP */

