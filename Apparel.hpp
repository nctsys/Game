/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Apparel.hpp
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 19:02
 */

#ifndef APPAREL_HPP
#define APPAREL_HPP

#include <iostream>
#include <string>

#include "Items.hpp"

class Apparel :public Items{
public:
    
    Apparel( const std::string& ap_name, long ap_id, long ap_bonus_type, const double& ap_weight, const double& ap_bonus ):
    Items( ap_name, ap_weight, ap_id )
    {
        this->apparel._apparel_bonus = ap_bonus;
        this->apparel._apparel_bonus_type = ap_bonus_type;
    }
    virtual ~Apparel(){}
    
    std::string GetName() const { return Items::GetName(); }
    double GetWeight() const { return Items::GetWeight(); }
    void SetApparelInfo( const std::string& attr ){ this->apparel._apparel_info = attr;}
    std::string GetApparelInfo() const { return this->apparel._apparel_info; }
    long GetApparelBonusType() const { return this->apparel._apparel_bonus_type;} 
    double GetApparelBonusValue() const { return this->apparel._apparel_bonus; }
    long GetID() const { return Items::GetID(); }
    
private:
    
    struct apparel_attributes
    {
        std::string _apparel_info;
        long _apparel_bonus_type;
        double _apparel_bonus = 0;
                
    } apparel;
    
    
};

#endif /* APPAREL_HPP */

