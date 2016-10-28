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

#include "Items.hpp"
#include "Gem.hpp"

class Weapon : public Items
{
public:
   Weapon( const std::string& wp_name, long weapon_id, const double& atk_lvl, const double& def_lvl, const double& weight):
    Items( wp_name, weight, weapon_id )
    {
        SetAttributes( atk_lvl, def_lvl );
    }
    virtual ~Weapon(){}
    
    std::string getName() const { return Items::GetName(); }
    double getAttackLevel() const { return this->weapon._attack_lvl; }
    double getDefenseLevel() const { return this->weapon._defense_lvl; }
    double getWeight() const { return Items::GetWeight(); }
    void AddGem( Gem *gem ){ this->weapon._gem = gem;}
    Gem* GetGem(){ return this->weapon._gem;}
    bool getCraftStatus() const { return this->weapon._crafted; }
    
private:
    
    struct weapon_attr
    {
      
        double _attack_lvl = 0;
        double _defense_lvl = 0;
        bool _crafted = false;
        Gem* _gem;
    } weapon;
    
    void SetAttributes( const double& atk_lvl, const double& def_lvl)
    {
        if( GetGem() != NULL )
        {
            this->weapon._attack_lvl = atk_lvl + GetGem()->getBonus();
            this->weapon._defense_lvl = def_lvl + GetGem()->getBonus();
            this->weapon._crafted = true;
        }
        else
        {
            this->weapon._attack_lvl = atk_lvl;
            this->weapon._defense_lvl = def_lvl;
            this->weapon._crafted = false;
        }
        
    }
};

#endif /* WEAPPON_HPP */

