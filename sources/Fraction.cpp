#include <iostream>
#include "Fraction.hpp"
using namespace ariel;

string Fraction::to_string() {
    return this->numerator + " / " + this->denominator;
}