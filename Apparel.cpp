/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Apparel.cpp
 * Author: diego
 * 
 * Created on 19 de Outubro de 2016, 19:02
 */

#include "Apparel.hpp"

Apparel::Apparel(const std::string& ap_name, long& ap_id, const std::string& ap_attr, const double& ap_bonus)
{
    SetApparelAttr( ap_name, ap_id, ap_attr, ap_bonus );
}

void Apparel::SetApparelAttr(const std::string& ap_name, long& ap_id, const std::string& ap_attr, const double& ap_bonus)
{
    this->apparel._apparel_name = ap_name;
    this->apparel._apparel_id = ap_id;
    this->apparel._apparel_attr = ap_attr;
    this->apparel._apparel_bonus = ap_bonus;
}

Apparel::~Apparel() {}

