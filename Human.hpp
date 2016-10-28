// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Human.
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 20:15
 */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Character.hpp"
#include "Armor.hpp"
#include "Apparel.hpp"
#include "Weapon.hpp"

class Human : public Character
{
public:
        //tentar substituir armor, weapon, apparel por um único item
    Human( const std::string& ch_name ) : Character( ch_name, IDs::race::CHAR_HUMAN )
    {
        SetExp();
        SetCharStats();
    }
    virtual ~Human(){}
    
    long GetCharLevel() const { return this->_human._lvl; }
    long GetExp() const { return EXP_level; }
    double GetCharAttack() const { return this->_human._atacklevel; }
    double GetCharDefense() const { return this->_human._defenselevel; }
    std::string GetName() const { return Character::GetName(); }
    std::string GetRace() const { return Races::GetRace(); }
    void AddArmor( Armor* armor){ this->_human._armor = armor; }
    void AddWeapon( Weapon* weapon ){ this->_human._weapon = weapon; }
    void AddApparel( Apparel* apparel){ this->_human._apparel = apparel; }
    Armor* GetArmor() const { return this->_human._armor; }
    Weapon* GetWeapon() const { return this->_human._weapon; }
    Apparel* GetApparel() const { return this->_human._apparel; }
    
    void SetCharStats()
    {
       
        double def, atk;
       
        this->_human._exp_up = GetExp();
            
        if( GetArmor() != NULL && GetWeapon() != NULL && GetApparel() != NULL )
        {
            this->_human._stamina-= ( GetArmor()->getWeight() + GetWeapon()->getWeight() );
            
            atk = GetWeapon()->getAttackLevel() - ( this->_human._curse + this->_human._poison + this->_human._bleeding );
            def = GetArmor()->getDefenselvl() + GetWeapon()->getDefenseLevel() - ( this->_human._curse + this->_human._poison + this->_human._bleeding );
        
            this->_human._atacklevel+= atk;
            this->_human._defenselevel+= def;
                    
            this->_human._hp-= ( this->_human._curse + this->_human._poison + this->_human._bleeding );
            this->_human._mp+= this->_human._inteligence + this->_human._faith;
            this->_human._exp+= 1;
            this->_human._char_carry = GetArmor()->GetWeight() + GetWeapon()->GetWeight();
            
            switch( GetApparel()->GetApparelBonusType() )
            {
                case IDs::APPAREL_ATTACK:
                    this->_human._atacklevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_CARRY_WEIGHT:
                    this->_human._carry_weight+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_DEFENSE:
                    this->_human._defenselevel+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_MAGIC:
                    this->_human._mp+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STAMINA:
                    this->_human._stamina+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_STRENGHT:
                    this->_human._strenght+= GetApparel()->GetApparelBonusValue();
                    break;
                case IDs::APPAREL_lUCKY:
                    this->_human._lucky+= GetApparel()->GetApparelBonusValue();
                    break;
                default:
                    break;
            }
        }
        
    }
     
private:
        
    struct human_attributes 
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
            
    }_human;
    long EXP_level;
    
    void SetExp()
    {
        EXP_level = this->_human._lvl * 3850; 
    }
    
};

#endif /* HUMAN_HPP */

