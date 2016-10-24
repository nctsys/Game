
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Items.hpp"

class Character
{
public:
    
    Character (){}
    virtual ~Character (){}

    virtual void SetCharStats( const std::string& _chname, long& _race, int& _level, Armor* armor, Weapon* weapon, Apparel* apparel ) = 0;
       	  	
    struct char_data
    {
    	//CHARACTER 
	    std::string _name;                  //Character Name
	    long _id;                           //Race ID
	    long _lvl;  			//Character Level (must be start as one)
	    //STATS
	    double _hp;				//Health Points
	    double _mp;				//Magic Points
	    double _stamina;                    //Stamina Points
            double _dex;                        //Dex Points
	    double _exp;			//Experience Points
	    double _strenght;                   //Strenght Points
	    //EXTRA STATS
	    double _inteligence;                //Inteligence Points
	    double _faith;                      //Faith Points
	    double _lucky;                      //Lucky Points 
	    double _atacklevel;                 //Atack Level
	    double _defenselevel;               //Defense Level
	    //SICK STATS
	    double _poison;                     //Poison Level
	    double _curse;                      //Curse Level
            double _bleeding;
            //ARMOR
            std::string _armor_name;            //Armor Name
            std::string _armor_gem_attr;        //Gem Attributes
            double _armor_defence;              //Armor Defence Points
            double _armor_gem_bonus;            //Gem Bonus
            double _armor_weight;               //Armor Weight
            bool _armor_crafted;                //Armor Crafted ?
            //WEAPONS
            std::string _weapon_name;           //Weapon Name
            std::string _weapon_gem_attr;       //Gem Attributes
            double _weapon_attack;              //Weapon Attack Points
            double _weapon_defence;             //Weapon Defence Points
            double _weapon_weight;              //Weapon Weight    
            long _weapon_hand;                  //Weapon Hand
            double _weapon_gem_bonus;           //Gem Bonus 
            bool _weapon_crafted;               //Weapon Crafted ?
            
            double _min_velocity;               //Walk
            double _max_velocity;               //Run     
            
	    
	} _character;

 
private:
	
    bool death;
    double expUpLevel;
    long x_pos;
    long y_pos;

};

#endif // CHARACTER_H
