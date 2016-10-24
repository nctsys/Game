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

#include "IDs.hpp"

class Apparel {
public:
    
    Apparel( const std::string& ap_name, long& ap_id, const std::string& ap_attr, const double& ap_bonus );
    virtual ~Apparel();
    
    std::string getName() const { return this->apparel._apparel_name; }
    std::string getApparelAttr() const { return this->apparel._apparel_attr; }
    double getApparelBonus() const { return this->apparel._apparel_bonus; }
    
private:
    
    struct apparel_attributes
    {
        std::string _apparel_name;
        long _apparel_id;
        std::string _apparel_attr;
        double _apparel_bonus;
    } apparel;
    
    void SetApparelAttr( const std::string& ap_name, long& ap_id, const std::string& ap_attr, const double& ap_bonus );
    long getID() const { return this->apparel._apparel_id; }

};

#endif /* APPAREL_HPP */

