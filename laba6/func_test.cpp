#include "gtest/gtest.h"
#include "func.h"

TEST(constructor, test1){
    ProperFraction fraction(1,2);
    int a = fraction.GetNumerator(fraction);
    int b = fraction.GetDenominator(fraction);
    ASSERT_EQ(a,1);
    ASSERT_EQ(b,2);
}

TEST(reducing, test2) {
    ProperFraction fraction(2, 4);
    int a = fraction.GetNumerator(fraction);
    int b = fraction.GetDenominator(fraction);
    ASSERT_EQ(a,1);
    ASSERT_EQ(b,2);
}

TEST(sum, test3) {
    ProperFraction a(1, 2);
    ProperFraction b(1, 3);
    ProperFraction c = a + b;
    ASSERT_EQ(c.GetNumerator(c), 5);
    ASSERT_EQ(c.GetDenominator(c), 6);
}

TEST(minus, test4) {
    ProperFraction a(8, 5);
    ProperFraction b(4, 7);
    ProperFraction c = a - b;
    ASSERT_EQ(c.GetNumerator(c), 36);
    ASSERT_EQ(c.GetDenominator(c), 35);
}
