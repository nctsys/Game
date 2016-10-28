// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Races.
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 20:17
 */

#ifndef RACES_HPP
#define RACES_HPP

#include <string>
#include "IDs.hpp"

class Races
{
public:
    
    Races( const long& race_id ){ SetRace( race_id );}
    virtual ~Races(){}
    
    std::string GetRace() const { return race; }
    
private:
    
    std::string race;
   
    void SetRace( const long& race_id)
    {
        switch( race_id )
        {
            case IDs::race::CHAR_DWARF:
                race = "Dwarf";
                break;
            case IDs::race::CHAR_ELF:
                race = "Elf";
                break;
            case IDs::race::CHAR_HUMAN:
                race = "Human";
                break;
            case IDs::race::CHAR_ORC:
                race = "Orc";
                break;
            case IDs::race::GOD:
                race = "God";
                break;
            default:
                break;
        }
    }
};

#endif /* RACES_HPP */

