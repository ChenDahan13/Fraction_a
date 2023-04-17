#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel {
    class Fraction {
        int numerator;
        int denominator;
        public:
            Fraction(int numerator = 1, int denominator = 2){
                this->numerator = numerator;
                if(denominator != 0)    
                    this->denominator = denominator;
                else {
                    throw invalid_argument("Denominator can'r be zero");
                    return;
                }
            }
            int getNumerator() {
                return  numerator;
            }
            int getDenominator() {
                return denominator;
            }
            string to_string();
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator==(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            Fraction operator-(int other) const;
            Fraction operator+(double other) const;
            Fraction operator+(int other) const;
            bool operator>(double other) const;
            Fraction& operator++(int);
            Fraction& operator--();
            ostream& operator<<(ostream& output);
            istream& operator>>(istream& input);
            operator float() const;
    };
}