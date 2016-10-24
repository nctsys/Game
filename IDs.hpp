// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Races.hpp
 * Author: diego
 *
 * Created on 19 de Outubro de 2016, 13:08
 */

#ifndef IDs_HPP
#define IDs_HPP

namespace IDs
{
    
    enum 
    {
        //Race
        CHAR_HUMAN = 1,
        CHAR_ORC = 2,
        CHAR_DWARF = 3,
        CHAR_ELF = 4,
        GOD = 100000
    } typedef race;
    
    enum
    {
        //Base Class
        CLASS_WARRIOR = 1000,
        CLASS_MAGE = 2000,
        CLASS_ARCHER = 3000
    } typedef baseclass;
    
    enum
    {    
        //Medium Class
        SUBCLASS_MEDIUM_WARRIOR = 1001,
        SUBCLASS_MEDIUM_PALADIN = 1277,
        SUBCLASS_MEDIUM_MAGE = 2001,
        SUBCLASS_MEDIUM_ARCHER = 3001,
        SUBCLASS_MEDIUM_MAGE_ARCHER = 3277,
    } typedef mediumclass;

    enum
    {
        //Master Class
        SUBCLASS_MASTER_WARRIOR = 1002,
        SUBCLASS_MASTER_PALADIN = 1278,
        SUBCLASS_MASTER_MAGE = 2002,
        SUBCLASS_MASTER_ARCHER = 3002,
        SUBCLASS_MASTER_MAGE_ARCHER = 3278,
    } typedef masterclass;

    enum
    {
        //Elite Class
        SUBCLASS_ELITE_WARRIOR = 1003,
        SUBCLASS_ELITE_PALADIN = 1279,
        SUBCLASS_ELITE_MAGE = 2003,
        SUBCLASS_ELITE_ARCHER = 3003,
        SUBCLASS_ELITE_MAGE_ARCHER = 3279
    } typedef eliteclass;

    enum
    {
        //Base Transitional Class 
        SUBCLASS_PALADIN = 1276,        //[warrior -> mage or mage -> warrior]
        SUBCLASS_MAGE_ARCHER = 3276,    //[archer -> mage or mage -> archer]
        SUBCLASS_SNAKE = 3100           //[warrior -> archer or archer -> warrior]
    } typedef tclass;
    
    enum
    {
        //High Class (no transitions)
        SUBCLASS_BLACK_PALADIN = 1280,
        SUBCLASS_LIGHT_PALADIN = 1281,
        SUBCLASS_ASSASSIN = 3101,
        SUBCLASS_ELEMENTAL_MAGE = 2004,
        SUBCLASS_DARK_MAGE = 2005,
        SUBCLASS_LIGHT_MAGE = 2006,
        SUBCLASS_DARK_ARCHER = 3280,
        SUBCLASS_LIGHT_ARCHER = 3281
    } typedef highclass;

    //ARMOR
    enum
    {
        ARMOR_HEAD = 100,
        ARMOR_ARMS = 101,
        ARMOR_TORSO = 102,
        ARMOR_LEGS = 103,
        ARMOR_BASIC_SET = 104,
        ARMOR_MEDIUM_SET = 105,
        ARMOR_ELITE_SET = 106,
        ARMOR_UNIQUE_SET = 107,
        ARMOR_GODS_SET = 108,
    } typedef armor;
    
    enum
    {
        RING = 201,
        NECKLACE = 202
    } typedef apparell;
    
    //WEAPONS
    enum
    {
        LEFT_HAND,
        RIGHT_HAND,
    } typedef hand;
    
}


#endif /* IDs_HPP */

