// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dwarf.
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 20:15
 */

#ifndef DWARF_HPP
#define DWARF_HPP

#include "Character.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Apparel.hpp"

class Dwarf : public Character
{
public:

    Dwarf( const std::string& _chname ) : Character( _chname, IDs::race::CHAR_DWARF)
    {
        SetExp();
        SetCharStats();
    }
    
    virtual ~Dwarf(){}
    
    long GetCharLevel() const { return this->_dwarf._lvl; }
    long GetExp() const { return EXP_level; }
    double GetCharAttack() const { return this->_dwarf._atacklevel; }
    double GetCharDefense() const { return this->_dwarf._defenselevel; }
    std::string GetName() const { return Character::GetName(); }
    std::string GetRace() const { return Races::GetRace(); }
    void AddArmor( Armor* armor){ this->_dwarf._armor = armor; }
    void AddWeapon( Weapon* weapon ){ this->_dwarf._weapon = weapon; }
    void AddApparel( Apparel* apparel){ this->_dwarf._apparel = apparel; }
    Armor* GetArmor() const { return this->_dwarf._armor; }
    Weapon* GetWeapon() const { return this->_dwarf._weapon; }
    Apparel* GetApparel() const { return this->_dwarf._apparel; }
    
private:
    
    long EXP_level;
    virtual void SetExp()
    {
        EXP_level = this->_dwarf._lvl * 3500; 
    }
    
    struct dwarf_attributes 
    {
        //STATS
        long _lvl = 1;  			//Character Level (must be start as one)
        double _hp = 100;			//Health Points
        double _mp = 10;                        //Magic Points
        double _stamina = 10;                   //Stamina Points
        double _dex = 5;                        //Dex Points
        long _exp = 0;                          //Experience Points
        long _exp_up ;                          //Experience to up level
        double _strenght = 6;                   //Strenght Points
        //EXTRA STATS
        double _inteligence = 4;                //Inteligence Points
        double _faith = 0.4;                    //Faith Points
        double _lucky = 0.8;                    //Lucky Points 
        double _atacklevel = _strenght + _dex;  //Atack Level
        double _defenselevel = 0;               //Defense Level
        //SICK STATS
        double _poison = 0;                     //Poison Level
        double _curse = 0;                      //Curse Level
        double _bleeding = 0;                   //Bleeding Level
        double _carry_weight = 30;
        double _char_carry ;
        Armor* _armor;
        Weapon* _weapon;
        Apparel* _apparel;
            
    }_dwarf;
    
    virtual void SetCharStats()
    {
        double def, atk;
       
        this->_dwarf._exp_up = GetExp();
            
        if( GetArmor() != NULL && GetWeapon() != NULL && GetApparel() != NULL )
        {
            this->_dwarf._stamina-= ( GetArmor()->getWeight() + GetWeapon()->getWeight() );
            
            atk = GetWeapon()->getAttackLevel() - ( this->_dwarf._curse + this->_dwarf._poison + this->_dwarf._bleeding );
            def = GetArmor()->getDefenselvl() + GetWeapon()->getDefenseLevel() - ( this->_dwarf._curse + this->_dwarf._poison + this->_dwarf._bleeding );
        
            this->_dwarf._atacklevel+= atk;
            this->_dwarf._defenselevel+= def;
                    
            this->_dwarf._hp-= ( this->_dwarf._curse + this->_dwarf._poison + this->_dwarf._bleeding );
            this->_dwarf._mp+= this->_dwarf._inteligence + this->_dwarf._faith;
            this->_dwarf._exp+= 1;
            this->_dwarf._char_carry = GetArmor()->GetWeight() + GetWeapon()->GetWeight();
            
            switch( GetApparel()->GetApparelBonusType() )
            {
                case IDs::APPAREL_ATTACK:
                    this->_dwarf._atacklevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_CARRY_WEIGHT:
                    this->_dwarf._carry_weight+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_DEFENSE:
                    this->_dwarf._defenselevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_MAGIC:
                    this->_dwarf._mp+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STAMINA:
                    this->_dwarf._stamina+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STRENGHT:
                    this->_dwarf._strenght+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_lUCKY:
                    this->_dwarf._lucky+= GetApparel()->GetApparelBonusValue();
                    break;
                default:
                    break;
            }
        }        
    }
    
};

#endif /* DWARF_HPP */

