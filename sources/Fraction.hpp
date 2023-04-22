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
            Fraction(int num = 1, int den = 2): numerator(num){  
                if(den != 0) {
                    this->denominator = den;
                } else {
                    throw invalid_argument("Denominator can't be zero");
                    return;
                }
                this->reduceFraction();
            }
            void setNumerator(int num) {
                this->numerator = num;
            }
            void setDenominator(int num) {
                this->denominator = num;
            }
            int getNumerator() const{
                return  numerator;
            }
            int getDenominator() const{
                return denominator;
            }
            string to_string();

            /*----------- Fractions Operators ----------*/
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator==(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            /*------------------------------------------*/
            
            /*------------ Int Operators ------------*/
            Fraction operator-(int other) const;
            Fraction operator+(int other) const;
            /*---------------------------------------*/
            
            /*------------ Double Operators ----------*/
            Fraction operator+(double other) const;
            friend Fraction operator*(double other, const Fraction& fract);
            bool operator>(double other) const;
            /*----------------------------------------*/
            
            /*----------- Self Operators -----------*/
            Fraction& operator++(int);
            Fraction& operator--();
            Fraction& reduceFraction();
            /*--------------------------------------*/
            
            /*--------- Stream Operators ---------*/
            friend ostream& operator<<(ostream& output, const Fraction& fract);
            friend istream& operator>>(istream& input, Fraction& fract);
            /*------------------------------------*/

            /*---------- Other -----------*/
            int gcd(int num1, int num2);
            /*----------------------------*/
            
    };
}
ariel::Fraction doubleToFraction(double other);