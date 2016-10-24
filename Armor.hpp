/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armor.hpp
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 15:24
 */

#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <iostream>
#include <string>

#include "Gem.hpp"
#include "IDs.hpp"

class Armor {
public:
    
    Armor( const std::string& ar_name, long& armor_id, bool crafted, Gem* _gem, const double& def_attr, const double& weight );
    virtual ~Armor();
    
    std::string getArmorName() const { return this->armor._name; }
    long getArmorId() const { return this->armor._armor_id; }
    bool getCraftedStatus() const { return this->armor._crafted; }
    double getDefenselvl() const { return this->armor._def_lvl; }
    double getWeight() const { return this->armor._armor_weight; }
    std::string getGemAttr() const { return this->armor._gem_attr; }
    double getGemBonus() const { return this->armor._gem_bonus; }
    
private:
    
    struct armor_attr
    {
        std::string _name;
        long _armor_id;
        bool _crafted;
        double _def_lvl;
        double _armor_weight;
        std::string _gem_attr;
        double _gem_bonus;
    } armor;
    
    void SetArmorAttr( const std::string& ar_name, long& armor_id, bool crafted, Gem* _gem, const double& def_attr, const double& weight );
};

#endif /* ARMOR_HPP */

