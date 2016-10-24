/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weappon.cpp
 * Author: diego
 * 
 * Created on 19 de Outubro de 2016, 15:24
 */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& wp_name, long& weapon_id, long& hand_id, 
        const double& atk_lvl, const double& def_lvl, const double& weight, bool crafted, Gem* gem) 
{
    SetAttributes( wp_name, weapon_id, hand_id, atk_lvl, def_lvl, weight, crafted, gem );
}

void Weapon::SetAttributes(const std::string& wp_name, long& weapon_id, long hand_id, 
        const double& atk_lvl, const double& def_lvl, const double& weight, bool crafted, Gem* gem)
{
    this->weapon._name = wp_name;
    this->weapon._weapon_id = weapon_id;
    this->weapon._weapon_hand = hand_id;
    this->weapon._attack_lvl = atk_lvl + gem->getBonus();
    this->weapon._defense_lvl = def_lvl + gem->getBonus();
    this->weapon._weapon_weight = weight;
    this->weapon._gem_attr = gem->getAttr();
    this->weapon._crafted = crafted;
    this->weapon._gem_bonus = gem->getBonus();
}

Weapon::~Weapon() {}

