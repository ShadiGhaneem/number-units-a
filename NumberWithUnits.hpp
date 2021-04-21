
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


namespace ariel
{

    class NumberWithUnits
    {
        private:
            double n;
            string u;  
    
        public:
            NumberWithUnits(double n , const string &u);
        
            double getNum()const{
                return n;
            }

            string getUnit()const{
                return u;
            }
            static void read_units(std::ifstream &units_file);
    
            friend NumberWithUnits operator+(const NumberWithUnits &number1);
            friend NumberWithUnits operator+(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend NumberWithUnits operator+=(NumberWithUnits &number1, const NumberWithUnits &number2);

            friend NumberWithUnits operator-(const NumberWithUnits &number1);
            friend NumberWithUnits operator-(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend NumberWithUnits operator-=(NumberWithUnits &number1, const NumberWithUnits &number2);

            friend bool operator>(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend bool operator>=(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend bool operator<(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend bool operator<=(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend bool operator==(const NumberWithUnits &number1, const NumberWithUnits &number2);
            friend bool operator!=(const NumberWithUnits &number1, const NumberWithUnits &number2);

            friend NumberWithUnits operator++(NumberWithUnits &number);
            friend NumberWithUnits operator++(NumberWithUnits &number , int);
            friend NumberWithUnits operator--(NumberWithUnits &number);
            friend NumberWithUnits operator--(NumberWithUnits &number , int);

            friend NumberWithUnits operator*(const double number, const NumberWithUnits &number2);
            friend NumberWithUnits operator*(const NumberWithUnits &number2, const double number);

            friend NumberWithUnits operator*=(const double number, const NumberWithUnits &number2);
            friend NumberWithUnits operator*=(const NumberWithUnits &number2, const double number);

            friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &number2);

            friend std::istream &operator>>(std::istream &is, NumberWithUnits &number2);

    };
}