#include "func.h"
#include <stdlib.h>

ProperFraction::ProperFraction(int numerator, int denominator) {
    if (denominator == 0 || abs(numerator) > abs(denominator)) {
        std::cout << "Incorrect" << std::endl;
        exit(1);
    }
    else {
        this -> numerator = numerator;
        this -> denominator = denominator;
        FractionReduction();
    }
}

ProperFraction::ProperFraction(const ProperFraction &origin) {
    this -> numerator = origin.numerator;
    this -> denominator = origin.denominator;
    FractionReduction();
}

void ProperFraction::FractionReduction() {
    for (int i = std::min(abs(numerator), abs(denominator)); i > 0; --i) {
        if (abs(numerator) % i == 0 && abs(denominator) % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }
}

int ProperFraction::GetNumerator(ProperFraction) {
    return numerator;
}

int ProperFraction::GetDenominator(ProperFraction) {
    return denominator;
}

void ProperFraction::FractionSum(int num) {
    this -> numerator += num * denominator;
    this -> denominator = denominator;
    FractionReduction();
}

void ProperFraction::FractionSum(ProperFraction num) {
    this -> numerator = this -> numerator * num.denominator + this-> denominator * num.numerator;
    this -> denominator *= num.denominator;
    FractionReduction();
}

void ProperFraction::FractionMultiplication(int multiplier) {
    this -> numerator *= multiplier;
    this -> denominator = denominator;
    FractionReduction();
}

void ProperFraction::FractionMultiplication(ProperFraction multiplier) {
    this-> numerator *= multiplier.numerator;
    this-> denominator *= multiplier.denominator;
    FractionReduction();
}

void ProperFraction::FractionDivision(int divider) {
    if (divider == 0) {
        std::cout << "You can't divide by 0" << std:: endl;
        exit(1);
    } else {
        denominator *= divider;
    }
    this -> numerator = numerator;
    FractionReduction();
}

void ProperFraction::FractionDivision(ProperFraction divider) {
    if (divider.numerator == 0) {
        std::cout << "You can't divide fractions because numerator is 0" << std::endl;
        exit(1);
    } else {
        this->numerator *= divider.denominator;
        this->denominator *= divider.numerator;
    }
}

void ProperFraction::FractionOutput() {
    if (numerator * denominator < 0)
        std::cout << "The fraction is " << "-" << abs(numerator) << "/" << abs(denominator) << std::endl;
    else if (numerator * denominator > 0)
        std::cout << "The fraction is "  << (numerator) << "/" << (denominator) << std::endl;
    else
        std::cout << "The fraction is 0" << std::endl;
}