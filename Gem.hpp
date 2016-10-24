/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gem.hpp
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 16:12
 */

#ifndef GEM_HPP
#define GEM_HPP

#include <iostream>
#include <string>

#include "IDs.hpp"

class Gem {
public:
    
    Gem( const std::string& gem_name, long& gem_id, const std::string& gem_attr, const double& gem_bonus );
    virtual ~Gem();
    
    std::string getName() const { return this->gem._gem_name; }
    std::string getAttr() const { return this->gem._gem_attr; }
    double getBonus() const { return this->gem._gem_bonus; }
    
private:
    
    struct gem_attr
    {
      std::string _gem_name;
      long gem_id;
      std::string _gem_attr;
      double _gem_bonus;
    } gem;
    
    void SetGemAttr( const std::string& gem_name, long& gem_id, const std::string& gem_attr, const double& gem_bonus );

};

#endif /* GEM_HPP */

