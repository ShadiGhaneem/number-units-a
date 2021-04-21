  
#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    static map<string, map<string, double>> unitList; 

    NumberWithUnits::NumberWithUnits(double n , const string &u)
    {
        this->n = n;
        this->u = u;
    }

    void NumberWithUnits::read_units(std::ifstream &units_file){
    }   
    NumberWithUnits operator+(const NumberWithUnits &number1){
        return number1;
    }
    NumberWithUnits operator+(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return number1;
    }
    NumberWithUnits operator+=(NumberWithUnits &number1, const NumberWithUnits &number2){
        return number1;
    }
    NumberWithUnits operator-(const NumberWithUnits &number2){
        return number2;
    }
    NumberWithUnits operator-(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return number1;
    }
    NumberWithUnits operator-=(NumberWithUnits &number1, const NumberWithUnits &number2){
        return number1;
    }

    bool operator>(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return true;
    }
    bool operator>=(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return  true;
    }
    bool operator<(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return true;
    }
    bool operator<=(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return true;
    }
    bool operator==(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return  true;
    }
    bool operator!=(const NumberWithUnits &number1, const NumberWithUnits &number2){
        return true;
    }
    NumberWithUnits operator++(NumberWithUnits &number){
        return number;
    }
    NumberWithUnits operator++(NumberWithUnits &number , int){
        return number;
    }
    NumberWithUnits operator--(NumberWithUnits &number){
        return number;
    }
    NumberWithUnits operator--(NumberWithUnits &number , int){
        return number;
    }
    NumberWithUnits operator*(const double number, const NumberWithUnits &number2){
        return number2;
    }
    NumberWithUnits operator*(const NumberWithUnits &number2, const double number){
        return number2;
    }
    std::ostream &operator<<(std::ostream &os, const NumberWithUnits &number2){
        return os;
    }
    std::istream &operator>>(std::istream &is, NumberWithUnits &number2){
        return is;
    }
};
