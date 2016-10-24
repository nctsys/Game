/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gem.cpp
 * Author: diego
 * 
 * Created on 19 de Outubro de 2016, 16:12
 */

#include "Gem.hpp"

Gem::Gem(const std::string& gem_name, long& gem_id, const std::string& gem_attr, const double& gem_bonus)
{
    SetGemAttr( gem_name, gem_id, gem_attr, gem_bonus );
}

void Gem::SetGemAttr( const std::string& gem_name, long& gem_id, const std::string& gem_attr, const double& gem_bonus )
{
    this->gem._gem_name = gem_name;
    this->gem.gem_id = gem_id;
    this->gem._gem_attr = gem_attr;
    this->gem._gem_bonus = gem_bonus;
}

Gem::~Gem() {}

