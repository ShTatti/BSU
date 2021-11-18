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
    void ProperFraction::FractionDivisionn(int devider);
    void ProperFraction::FractionSum(ProperFraction num);
    void ProperFraction::FractionMultiplication(ProperFraction multiplier);
    void ProperFraction::FractionDivisionn(ProperFraction devider);
    void ProperFraction::FractionPrint();

private:
    int numerator;
    int denominator;
};