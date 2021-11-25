#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "weapon.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once


class BaseFighter {
    string name;
    Weapon* weapon;

public:
    BaseFighter() {
        name = "None";
        weapon = new Weapon;
    }

    virtual double attack() {
        return weapon->use();
    }

    virtual int health() {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<int> distr(3, 10);

        return distr(eng);
    }

    virtual double regen() {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<int> distr(15, 15);

        return (distr(eng)/100);
    }

    friend ostream& operator<<(ostream& os, const BaseFighter& f) {
        return os << "[" << f.name << " , " << *f.weapon << "]";
    }

};