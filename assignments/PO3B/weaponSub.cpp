#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <time.h>

#include "weapon.hpp"
#include "helpers.hpp"
#include "fighter.hpp"

class sword : public Weapon
{
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;

    sword();
};

class bow : public Weapon
{
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;

    bow();
};

class magicSpell: public Weapon
{
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;

    magicSpell();
};

class magicWeapon : public Weapon
{
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;

    magicWeapon();
    double use();
};

class fireWeapon : public Weapon{
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;

    fireWeapon();
    double use();
};


//constructors, lol
sword::sword(){
    srand(time(NULL));

    name = "sword";
    damage = ((rand()%3+1)==1)?"1.d.12": ((rand() % 3 + 1) == 2) ? "2.d.6": "3.d.4";
}

bow::bow(){
    srand(time(NULL));

    name = "bow";
    damage = ((rand() % 3 + 1) == 1) ? "1.d.8" : ((rand() % 3 + 1) == 2) ? "2.d.4" : "1.d.10";
}

magicSpell::magicSpell() {
    srand(time(NULL));

    name = "magic spell";
    damage = ((rand() % 3 + 1) == 1) ? "1.d.20" : ((rand() % 3 + 1) == 2) ? "2.d.10" : "5.d.4";
}

magicWeapon::magicWeapon(){
    srand(time(NULL));

    name = "magic weapon";
}

fireWeapon::fireWeapon(){
    name = "fire weapon";
}

//use functions
//magicWeapon::double use(){
//    int temp = dice->roll;
//    dice = (rand() % 3 + 1) == 1) ? "1.d.4" : "1.d.6";
//
//    return temp + dice->roll;
//}

//fireWeapon::double use(){
//    int temp = dice->roll;
//    dice = (rand() % 3 + 1) == 1) ? "1.d.4" : "1.d.6";
//
//    return temp + dice->roll;
//}