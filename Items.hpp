// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Items.
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 19:25
 */

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

class Items
{
public:
    
    Items(const std::string item_name , const double& item_weight = 0, long item_id = -1 )
    {
        this->_item._item_name = item_name;
        this->_item._item_weight = item_weight;
        this->_item._item_id = item_id;
    }
    virtual ~Items(){}
    
    std::string GetName() const { return this->_item._item_name ;}
    double GetWeight() const { return this->_item._item_weight; }
    long GetID() const { return this->_item._item_id; }
    
private:
    
    struct item_attributes
    {
       std::string _item_name;
       double _item_weight;
       long _item_id;
       
    } _item;
    
};

#endif /* ITEMS_HPP */

