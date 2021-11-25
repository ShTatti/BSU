#include "gtest/gtest.h"
#include "func.h"

TEST(GetNumeratorOfFraction, test1) {
    ProperFraction fraction(3,4);
    int a = fraction.GetNumerator(fraction);
    ASSERT_EQ(a,3);
}

TEST(СonstructorOfFrection, test1) {
    ProperFraction fraction(1,2);
    int a = fraction.GetNumerator(fraction);
    int b = fraction.GetDenominator(fraction);
    ASSERT_EQ(a,1);
    ASSERT_EQ(b,2);
}

TEST(ReducingOfFraction, test1) {
    ProperFraction fraction(2, 4);
    int a = fraction.GetNumerator(fraction);
    int b = fraction.GetDenominator(fraction);
    ASSERT_EQ(a,1);
    ASSERT_EQ(b,2);
}

TEST(MinusInDenominator, test1) {
    ProperFraction fraction(4, -9);
    ASSERT_EQ(fraction.GetNumerator(fraction), 4);
    ASSERT_EQ(fraction.GetDenominator(fraction), -9);
}

TEST(MinusInDenominatorAndNumerator, test1) {
    ProperFraction fraction(-4, -9);
    ASSERT_EQ(fraction.GetNumerator(fraction), -4);
    ASSERT_EQ(fraction.GetDenominator(fraction), -9);
}

TEST(NumeratorWithNull, test1){
    ProperFraction fraction(0,4);
    int a = fraction.GetNumerator(fraction);
    int b = fraction.GetDenominator(fraction);
    ASSERT_EQ(a,0);
    ASSERT_EQ(b,4);
}

TEST(FractionMultiplication, test1) {
    ProperFraction fraction1(1, 4);
    ProperFraction fraction2(1, 3);
    fraction1.FractionMultiplication(fraction2);
    ASSERT_EQ(fraction1.GetNumerator(fraction1), 1);
    ASSERT_EQ(fraction1.GetDenominator(fraction1), 12);
}

TEST(FractionSum, test1) {
    ProperFraction fraction1(1, 4);
    ProperFraction fraction2(1, 3);
    fraction1.FractionSum(fraction2);
    ASSERT_EQ(fraction1.GetNumerator(fraction1), 7);
    ASSERT_EQ(fraction1.GetDenominator(fraction1), 12);
}

TEST(FractionDivisionThesame, test1){
    ProperFraction fraction1(1,4);
    ProperFraction fraction2(1,4);
    fraction1.FractionDivision(fraction2);
    ASSERT_EQ(fraction1.GetNumerator(fraction1), 4);
    ASSERT_EQ(fraction1.GetDenominator(fraction1), 4);
}

TEST(FractionDivision, test1){
    ProperFraction fraction1(1,4);
    ProperFraction fraction2(3,7);
    fraction1.FractionDivision(fraction2);
    ASSERT_EQ(fraction1.GetNumerator(fraction1), 7);
    ASSERT_EQ(fraction1.GetDenominator(fraction1), 12);
}
