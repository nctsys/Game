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
#include "Items.hpp"

class Armor : public Items
{
public:
    
    Armor( const std::string& ar_name, long armor_id, const double& def_attr, const double& weight ):
    Items( ar_name, weight, armor_id )
    {
        SetArmorAttr( def_attr );
    }
    virtual ~Armor(){}
    
    std::string getArmorName() const { return Items::GetName(); }
    long getArmorId() const { return Items::GetID(); }
    double getDefenselvl() const { return this->armor._def_lvl; }
    double getWeight() const { return Items::GetWeight(); }
    
private:
    
    struct armor_attr
    {
        bool _crafted = false;
        double _def_lvl = 0;
    } armor;
    
    void SetArmorAttr( const double& def_attr )
    {
        this->armor._def_lvl = def_attr;
    }
};

#endif /* ARMOR_HPP */

