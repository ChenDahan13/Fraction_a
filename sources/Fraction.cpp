#include <iostream>
#include "Fraction.hpp"
using namespace ariel;
using namespace std;


Fraction doubleToFraction(double num) {
    int newNumer = int(num * 1000);
    Fraction f(newNumer, 1000);
    f.reduceFraction();
    return f;
}

int Fraction::gcd(int num1, int num2) {
    if (num1 >= num2) {
        for(int i = num2; i > 0 ; i--) {
            if(num1 % i == 0 && num2 % i == 0)
                return i; 
        }
    }
    else {
        for(int i = num1; i > 0 ; i--) {
            if(num1 % i == 0 && num2 % i == 0)
                return i; 
        }
    }
    return 0;
}

Fraction& Fraction::reduceFraction() {
    int d = gcd(this->numerator, this->denominator);
    if (d != 0) {
        this->numerator = this->numerator / d;
        this->denominator = this->denominator / d;
    }
    return *this;
}

string Fraction::to_string() {
    return std::to_string(this->numerator) + " / " + std::to_string(this->denominator);
}

Fraction Fraction::operator*(const ariel::Fraction& other) const{
    Fraction f(this->numerator*other.numerator, this->denominator*other.denominator);
    f.reduceFraction();
    return f;
} 

Fraction Fraction::operator+(const ariel::Fraction& other) const{
    int newNumerator = (this->numerator*other.denominator) + (this->denominator*other.numerator);
    int newDenominator = this->denominator*other.denominator;
    Fraction f(newNumerator, newDenominator);
    f.reduceFraction();
    return f;
}

Fraction Fraction::operator-(const ariel::Fraction& other) const {
    int newNumerator = (this->numerator*other.denominator) - (this->denominator*other.numerator);
    int newDenominator = this->denominator*other.denominator;
    Fraction f(newNumerator, newDenominator);
    f.reduceFraction();
    return f;
} 

Fraction Fraction::operator/(const ariel::Fraction& other) const{
    Fraction f(this->numerator*other.denominator, this->denominator*other.numerator);
    f.reduceFraction();
    return f;
} 

bool Fraction::operator>=(const ariel::Fraction& other) const{
    if(operator>(other) || operator==(other))
        return true;
    return false;
} 

bool Fraction::operator==(const ariel::Fraction& other) const{
    int sum = this->numerator*other.denominator - this->denominator*other.numerator;
    return (sum == 0) ? true : false;
} 

bool Fraction::operator<=(const ariel::Fraction& other) const{
    if(operator<(other) || operator==(other))
        return true;
    return false;
} 

bool Fraction::operator>(const ariel::Fraction& other) const{
    int sum = this->numerator*other.denominator - this->denominator*other.numerator;
    return (sum > 0) ? true : false;
} 

bool Fraction::operator<(const ariel::Fraction& other) const{
    int sum = other.numerator*this->denominator - other.denominator*this->numerator;
    return (sum > 0) ? true : false;
} 

Fraction Fraction::operator+(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator+(f1));
} 

Fraction ariel::operator*(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1*f);
    
} 

Fraction Fraction::operator+(int other) const{
    Fraction f1(other,1);
    return (this->operator+(f1));
} 

Fraction Fraction::operator-(int other) const{
    Fraction f1(other,1);
    return (this->operator-(f1));
} 

bool Fraction::operator>(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator>(f1));
} 

Fraction& Fraction::operator++(int) {
    int newNumer = this->numerator + this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return *this;
}

Fraction& Fraction::operator--() {
    int newNumer = this->numerator - this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return *this;
}

ostream& ariel::operator<<(ostream& output, const Fraction& f) {
    return (output << f.numerator << "/" << f.denominator);
}

istream& ariel::operator>>(istream& input, Fraction& f) {
    string fraction;
    input >> fraction;
    size_t pos = fraction.find('/'); // Searching if there a slash in input
    if(pos == string::npos) {
        throw invalid_argument("Fraction was written unright");
    }
    string numStr = fraction.substr(0, pos); // Puts to string until the index of the slash
    string denStr = fraction.substr(pos + 1); // Puts to string fron the index of the slash
    
    // Converts the strings to integers and updates the fraction
    f.setNumerator(stoi(numStr));
    f.setDenominator(stoi(denStr));
    return input;
}







