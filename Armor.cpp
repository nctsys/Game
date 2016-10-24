/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armor.cpp
 * Author: diego
 * 
 * Created on 19 de Outubro de 2016, 15:24
 */

#include "Armor.hpp"

Armor::Armor(const std::string& ar_name, long& armor_id, bool crafted, Gem* _gem, const double& def_lvl, const double& weight)
{
    SetArmorAttr( ar_name, armor_id, crafted, _gem, def_lvl, weight );
}

void Armor::SetArmorAttr(const std::string& ar_name, long& armor_id, bool crafted, Gem* gem, const double& def_lvl, const double& weight )
{    
    this->armor._name = ar_name;
    this->armor._armor_id = armor_id;
    this->armor._crafted = crafted;
    this->armor._def_lvl = def_lvl + gem->getBonus();
    this->armor._armor_weight = weight;
    this->armor._gem_attr = gem->getAttr();
    this->armor._gem_bonus = gem->getBonus();
}

Armor::~Armor() {}

