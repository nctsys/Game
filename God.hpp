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

#include "Character.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Apparel.hpp"

class God : public Character
{
public:

    God( const std::string& _chname ): Character( _chname, IDs::race::GOD )
    {   
        SetCharStats();
    }
    
    virtual ~God(){}
    
    long GetCharLevel() const { return this->_god._lvl; }
    long GetExp() const { return EXP_level; }
    double GetCharAttack() const { return this->_god._atacklevel; }
    double GetCharDefense() const { return this->_god._defenselevel; }
    std::string GetName() const { return Character::GetName(); }
    std::string GetRace() const { return Races::GetRace(); }
    void AddArmor( Armor* armor){ this->_god._armor = armor; }
    void AddWeapon( Weapon* weapon ){ this->_god._weapon = weapon; }
    void AddApparel( Apparel* apparel){ this->_god._apparel = apparel; }
    Armor* GetArmor() const { return this->_god._armor; }
    Weapon* GetWeapon() const { return this->_god._weapon; }
    Apparel* GetApparel() const { return this->_god._apparel; }

private:
    
    struct god_attributes 
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
            
    }_god;
  
    long EXP_level;
    
    virtual void SetExp()
    {
        EXP_level = this->_god._lvl * 3890;
    }
    
    virtual void SetCharStats()
    {
        double def, atk;
       
        this->_god._exp_up = GetExp();
            
        if( GetArmor() != NULL && GetWeapon() != NULL && GetApparel() != NULL )
        {
            this->_god._stamina-= ( GetArmor()->getWeight() + GetWeapon()->getWeight() );
            
            atk = GetWeapon()->getAttackLevel() - ( this->_god._curse + this->_god._poison + this->_god._bleeding );
            def = GetArmor()->getDefenselvl() + GetWeapon()->getDefenseLevel() - ( this->_god._curse + this->_god._poison + this->_god._bleeding );
        
            this->_god._atacklevel+= atk;
            this->_god._defenselevel+= def;
                    
            this->_god._hp-= ( this->_god._curse + this->_god._poison + this->_god._bleeding );
            this->_god._mp+= this->_god._inteligence + this->_god._faith;
            this->_god._exp+= 1;
            this->_god._char_carry = GetArmor()->GetWeight() + GetWeapon()->GetWeight();
            
            switch( GetApparel()->GetApparelBonusType() )
            {
                case IDs::APPAREL_ATTACK:
                    this->_god._atacklevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_CARRY_WEIGHT:
                    this->_god._carry_weight+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_DEFENSE:
                    this->_god._defenselevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_MAGIC:
                    this->_god._mp+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STAMINA:
                    this->_god._stamina+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STRENGHT:
                    this->_god._strenght+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_lUCKY:
                    this->_god._lucky+= GetApparel()->GetApparelBonusValue();
                    break;
                default:
                    break;
            }
        }
    }
    
};


#endif /* GOD_HPP */

