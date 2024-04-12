#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "mitech.h"

using namespace std;

string MiTech::type() const {
    return _type;
}

string MiTech::country() const {
    return _country;
}

int MiTech::amount() const {
    return _amount;
}

void MiTech::settype(const string& type) {
    _type = type;
}

void MiTech::setcountry(const string& country) {
    _country = country;
}

void MiTech::setamount(const int& amount) {
    _amount = amount;
}



