#include <iostream>

class ProperFraction {
public:
    ProperFraction(int numerator, int denominator);
    ProperFraction(const ProperFraction& origin);
    void ProperFraction::FractionReduction();
    int ProperFraction::GetNumerator(ProperFraction);
    int ProperFraction::GetDenominator(ProperFraction);
    void ProperFraction::FractionSum(int num);
    void ProperFraction::FractionMultiplication(int multiplier);
    void ProperFraction::FractionDivision(int devider);
    void ProperFraction::FractionSum(ProperFraction num);
    void ProperFraction::FractionMultiplication(ProperFraction multiplier);
    void ProperFraction::FractionDivision(ProperFraction devider);
    void ProperFraction::FractionOutput();

private:
    int numerator;
    int denominator;
};