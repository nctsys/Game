
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Races.hpp"

class Character : public Races
{
public:
    
    Character ( std::string ch_name, const long race_id ) : Races( race_id)
    {
        this->_character._name = ch_name;
    }
    
    virtual ~Character (){}

    std::string GetRace() const { return Races::GetRace(); }
    std::string GetName() const { return this->_character._name; }
    
    struct char_data
    {
    	//CHARACTER 
        std::string _name;                  //Character Name
        long _id;                           //Race ID	    
    } _character;

 
private:
	

};

#endif // CHARACTER_H
