#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "weapon.hpp"
#include "helpers.hpp"
#include "fighter.hpp"
#include "weaponSub.cpp"

//it hates the word warrior
class paladin : public BaseFighter
{
public:
    string name;    // name of weapon
    Weapon* weapon;

    paladin();
};

class wizard : public BaseFighter
{
public:
    string name;    // name of weapon
    Weapon* weapon;

    wizard();
};

class archer : public BaseFighter
{
public:
    string name;    // name of weapon
    Weapon* weapon;

    archer();
};

class elf : public BaseFighter
{
public:
    string name;    // name of weapon
    Weapon* weapon;

    elf();
};


class dragonborn : public BaseFighter
{
public:
    string name;    // name of weapon
    Weapon* weapon;

    dragonborn();
};

paladin::paladin() {
    name = "paladin";
    weapon = new sword;
}

wizard::wizard() {
    name = "wizard";
    weapon = new magicSpell;
}

archer::archer() {
    name = "archer";
    weapon = new bow();
}

elf::elf() {
    name = "elf";
    weapon = new magicWeapon();
}

dragonborn::dragonborn() {
    name = "dragonborn";
    weapon = new fireWeapon();
}