#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Initial fractions") {
    Fraction f1(2,4);
    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 4);
    f1.reduceFraction();
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
}

TEST_CASE("Checks operators") {
    Fraction f1(1,2);
    Fraction f2(1,4);
    Fraction f3 = f1+f2;
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 4);
    f3 = f1-f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);
    f3 = f1*f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 8);
    f3 = f1/f2;
    CHECK(f3.getNumerator() == 2);
    CHECK(f3.getDenominator() == 1);
    f3 = 2.348*f1;
    CHECK(f3.getNumerator() == 587);
    CHECK(f3.getDenominator() == 500);
    f1++;
    CHECK(f1.getNumerator() == 3);
    CHECK(f1.getDenominator() == 2);
    --f2;
    CHECK(f2.getNumerator() == -3);
    CHECK(f2.getDenominator() == 4);
}

TEST_CASE("Complex problems") {
    Fraction f1(3,5);
    Fraction f2(7,9);
    Fraction f3 = f1+f2+1;
    CHECK(f3.getNumerator() == 107);
    CHECK(f3.getDenominator() == 45);
}

TEST_CASE("Checks boolean operators") {
    Fraction f1(3,4);
    Fraction f2(1,2);
    bool b1 = (f1 == f2);
    CHECK(b1 == false);
    b1 = (f1 > f2);
    CHECK(b1 == true);
    b1 = (f1 < f2);
    CHECK(b1 == false);
    b1 = (f1 >= f2);
    CHECK(b1 == true);
    b1 = (f1 <= f2);
    CHECK(b1 == false);
}