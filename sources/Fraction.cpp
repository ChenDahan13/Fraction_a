#include <iostream>
#include "Fraction.hpp"
using namespace ariel;
using namespace std;

string Fraction::to_string() {
    return "to_string";
}

Fraction Fraction::operator*(const ariel::Fraction& other) const{
    Fraction f1(1,2);
    return f1;
} 

Fraction Fraction::operator+(const ariel::Fraction& other) const{
    Fraction f1(1,2);
    return f1;
} 

Fraction Fraction::operator-(const ariel::Fraction& other) const {
    Fraction f1(1,2);
    return f1;
} 

Fraction Fraction::operator/(const ariel::Fraction& other) const{
    Fraction f1(1,2);
    return f1;
} 

bool Fraction::operator>=(const ariel::Fraction& other) const{
    cout << "operator >=" << endl;
    return false;
} 

bool Fraction::operator==(const ariel::Fraction& other) const{
    cout << "operator ==" << endl;
    return false;
} 

bool Fraction::operator<=(const ariel::Fraction& other) const{
    cout << "operator <=" << endl;
    return false;
} 

bool Fraction::operator>(const ariel::Fraction& other) const{
    cout << "operator >" << endl;
    return false;
} 

bool Fraction::operator<(const ariel::Fraction& other) const{
    cout << "operator <" << endl;
    return false;
} 

Fraction Fraction::operator+(double other) const{
    Fraction f1(1,2);
    return f1;
} 

Fraction Fraction::operator+(int other) const{
    Fraction f1(1,2);
    return f1;
} 

Fraction Fraction::operator-(int other) const{
    Fraction f1(1,2);
    return f1;
} 

bool Fraction::operator>(double other) const{
    cout << "operator <" << endl;
    return false;
} 

Fraction& Fraction::operator++(int) {
    return *this;
}

Fraction& Fraction::operator--() {
    return *this;
}

ostream& Fraction::operator<<(ostream& output) {
    return output;
}

istream& Fraction::operator>>(istream& input) {
    return input;
}

Fraction::operator float() const {
    return 1;
}





