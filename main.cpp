/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: diego
 *
 * Created on 12 de Outubro de 2016, 04:20
 */

#include <cstdlib>
#include "Human.hpp"
#include "Dwarf.hpp"
#include "Orc.hpp"
#include "Elf.hpp"
#include "God.hpp"

#include "Weapon.hpp"
#include "Apparel.hpp"
#include "Armor.hpp"

using namespace std;

int main(int argc, char** argv) 
{
    Weapon *wp = new Weapon( "weapon1", IDs::weapon_type::BOW, 0.9, 0, 0.3 );
    Armor *ar = new Armor( "Armor1", IDs::armor::ARMOR_BASIC_SET, 0.5, 0.7 );
    Apparel *ap = new Apparel( "Apparel1", IDs::apparell::RING, IDs::APPAREL_CARRY_WEIGHT, 0.2, 1.0 );

    Human *m = new Human( "lla" );
    Dwarf *d = new Dwarf( "lla" );
    Orc *o = new Orc( "lla" );
    Elf *e =new Elf( "lla" );
    God *g = new God( "lla" );
    
    m->AddWeapon( wp );
    m->AddArmor( ar );
    m->AddApparel( ap );
    
    d->AddApparel( ap );
    d->AddArmor( ar );
    d->AddWeapon( wp );
    
    o->AddApparel( ap );
    o->AddArmor( ar );
    o->AddWeapon( wp );
    
    e->AddApparel( ap );
    e->AddArmor( ar );
    e->AddWeapon( wp );
    
    g->AddApparel( ap );
    g->AddArmor( ar );
    g->AddWeapon( wp );
    
    delete wp;
    delete ar;
    delete ap;
    delete m;
    delete d;
    delete o;
    delete e;
    delete g;
    
    wp = NULL;
    ar = NULL;
    ap = NULL;
    m = NULL;
    d = NULL;
    o = NULL;
    e = NULL;
    g = NULL;
    
    return 0;
}

