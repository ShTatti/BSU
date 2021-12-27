#include "gtest/gtest.h"
#include "Calculator.h"
#include "Stack.h"

TEST(Stack, Push) {
    Stack<int> st(1);
    st.push("t");
    EXPECT_EQ(st.peek(), "t");
    EXPECT_EQ(st.size(), 1);
}

TEST(Stack, Pop&Peek) {
    Stack<int> st(5);
    st.push("t");
    st.push("a");
    st.push("t");
    st.push("t");
    st.push("i");
    st.pop();
    EXPECT_EQ(st.peek(), "t");
}

TEST(Stack, Size) {
    Stack<int> st(3);
    EXPECT_EQ(st.size(), 0);
    st.push("t");
    st.push("a");
    st.push("t");
    EXPECT_EQ(st.size(), 3);
    st.pop();
    st.pop();
    EXPECT_EQ(st.size(), 1);
}

TEST(Stack, IsEmpty) {
    Stack<int> st(1);
    EXPECT_EQ(st.IsEmpty(), true);
    st.push("t");
    EXPECT_EQ(st.IsEmpty(), false);
}

TEST(Stack, IsFull) {
    Stack<int> st(1);
    EXPECT_EQ(st.IsFull(), false);
    st.push("t");
    EXPECT_EQ(st.IsFull(), true);
}

TEST(Operator, SquareBrackets) {
    Stack<int> st(2);
    st.push("t");
    st.push("a");
    EXPECT_EQ(stack1.operator[](1), "a");
}

TEST(Operator, DoubleEqual) {
    Stack<int> st1(3);
    st1.push("t");
    st1.push("a");
    st1.push("t");
    Stack<int> st2(3);
    st2.push("t");
    st2.push("a");
    st2.push("t");
    Stack<int> st3(3);
    st3.push("m");
    st3.push("d");
    st3.push("a");
    EXPECT_EQ(st1 == st2, true);
    EXPECT_EQ(st1 == st3, false);
}

TEST(Operator, NotEqual)
{
    Stack<int> st1(3);
    st1.push("t");
    st1.push("a");
    st1.push("t");
    Stack<int> st2(3);
    st2.push("t");
    st2.push("a");
    st2.push("t");
    Stack<int> st3(3);
    st3.push("m");
    st3.push("d");
    st3.push("a");
    EXPECT_EQ(stack1 != stack2, false);
    EXPECT_EQ(stack1 != stack3, true);
}

TEST(Operator, Less)
{
    Stack<int> stack1(3);
    st1.push("t");
    st1.push("a");
    st1.push("t");
    Stack<int> stack2(5);
    st4.push("t");
    st4.push("a");
    st4.push("t");
    st4.push("t");
    st4.push("i");
    Stack<int> stack3(1);
    st5.push("t");
    EXPECT_EQ(st1 < st2, true);
    EXPECT_EQ(st1 < st3, false);
}

TEST(Operator, More)
{
    Stack<int> stack1(3);
    st1.push("t");
    st1.push("a");
    st1.push("t");
    Stack<int> stack2(5);
    st4.push("t");
    st4.push("a");
    st4.push("t");
    st4.push("t");
    st4.push("i");
    Stack<int> stack3(1);
    st5.push("t");
    EXPECT_EQ(stack1 > stack4, false);
    EXPECT_EQ(stack1 > stack5, true);
}

TEST(Calculator, CorrectWord) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("--1 + 2"), false);
    EXPECT_EQ(line.IsCorrect("1- 2"), false);
    EXPECT_EQ(line.IsCorrect("1 ++ 2"), false);
    EXPECT_EQ(line.IsCorrect("1?2 + 3"), false);
    EXPECT_EQ(line.IsCorrect("1 , 3"), false);
    EXPECT_EQ(line.IsCorrect("1.2.3 + 4"), false);
    EXPECT_EQ(line.IsCorrect(".1 + 2"), false);
    EXPECT_EQ(line.IsCorrect("1. + 2"), false);
}

TEST(Calculator, BracketsNumber)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect(" 1 - ( 2 - 3 ) "), true);,
    EXPECT_EQ(line.IsCorrect("( 1 - ( 1 - 2 )"), false);
}

TEST(Calculator, Brackets) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1+ ( )"), false);
    EXPECT_EQ(line.IsCorrect("1+ ( - 2)"), false);
    EXPECT_EQ(line.IsCorrect("1 + ( -2)"), true);
    EXPECT_EQ(line.IsCorrect("1 + ( 2 - 3 ) 4 * 5"), false);
    EXPECT_EQ(line.IsCorrect("1 + ( 2 - 2 ) ( 4 + 5 )"), false);
}

TEST(Calculator, AfterNumber) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 + 2"), true);
    EXPECT_EQ(line.IsCorrect("1 - 2"), true);
    EXPECT_EQ(line.IsCorrect("1 * 2"), true);
    EXPECT_EQ(line.IsCorrect("1 / 1"), true);
    EXPECT_EQ(line.IsCorrect("1 ( 2 + 3 )"), false);
    EXPECT_EQ(line.IsCorrect("1 + 2 3"), false);
    EXPECT_EQ(line.IsCorrect("( 1 - 2 ) * 3"), true);
}

TEST(Calculator, AfterPlus) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 + 2"), true);
    EXPECT_EQ(line.IsCorrect("1 + + 2"), false);
    EXPECT_EQ(line.IsCorrect("1 + - 2"), false);
    EXPECT_EQ(line.IsCorrect("1 + * 2"), false);
    EXPECT_EQ(line.IsCorrect("1 + / 2"), false);
    EXPECT_EQ(line.IsCorrect("1 + ( 2 - 3 )"), true);
    EXPECT_EQ(line.IsCorrect("( 1 + ) 2"), false);
}

TEST(Calculator, AfterMinus) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 - 2"), true);
    EXPECT_EQ(line.IsCorrect("1 - + 2"), false);
    EXPECT_EQ(line.IsCorrect("1 - - 2"), false);
    EXPECT_EQ(line.IsCorrect("1 - * 2"), false);
    EXPECT_EQ(line.IsCorrect("1 - / 2"), false);
    EXPECT_EQ(line.IsCorrect("1 - ( 2 - 3 )"), true);
    EXPECT_EQ(line.IsCorrect("( 1 - ) 2"), false);
}

TEST(Calculator, AfterMultiplication) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 * 2"), true);
    EXPECT_EQ(line.IsCorrect("1 * + 2"), false);
    EXPECT_EQ(line.IsCorrect("1 * - 2"), false);
    EXPECT_EQ(line.IsCorrect("1 * * 2"), false);
    EXPECT_EQ(line.IsCorrect("1 * / 2"), false);
    EXPECT_EQ(line.IsCorrect("( 1 * ) 2"), false);
    EXPECT_EQ(line.IsCorrect("1 * ( 2 - 3 )"), true);
}

TEST(Calculator, AfterDividion) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 / 2"), true);
    EXPECT_EQ(line.IsCorrect("1 / + 2"), false);
    EXPECT_EQ(line.IsCorrect("1 / - 2"), false);
    EXPECT_EQ(line.IsCorrect("1 / * 2"), false);
    EXPECT_EQ(line.IsCorrect("1 / / 2"), false);
    EXPECT_EQ(line.IsCorrect("( 1 / ) 2"), false);
    EXPECT_EQ(line.IsCorrect("1 / ( 2 - 3 )"), true);

}

TEST(Calculator, End) {
    Calculator line;
    EXPECT_EQ(line.IsCorrect("1 + 2"), true);
    EXPECT_EQ(line.IsCorrect("1 + ( 2 + 3 )"), true);
    EXPECT_EQ(line.IsCorrect("1 + 2 +"), false);
    EXPECT_EQ(line.IsCorrect("1 + 2 -"), false);
    EXPECT_EQ(line.IsCorrect("1 + 2 *"), false);
    EXPECT_EQ(line.IsCorrect("1 + 2 /"), false);
    EXPECT_EQ(line.IsCorrect("1 + ) 2 ("), false);
}

TEST(Calculator, Negative) {
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("-1 + 2")), 1);
    EXPECT_EQ(line.count(line.algorithm("1 * ( -2 )")), -2);
    EXPECT_EQ(line.count(line.algorithm("( -1 ) / 2")), -0.5);
    EXPECT_EQ(line.count(line.algorithm("1 - ( -2 )")), 3);
}

TEST(Calculator, Double) {
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("1.1 + 2.22")), 3.33);
    EXPECT_EQ(line.count(line.algorithm("1.11 * 2")), 2.22);
    EXPECT_EQ(line.count(line.algorithm("2 / 1")), 2);
    EXPECT_EQ(line.count(line.algorithm("2.222 - 1.111")), 1.111);
    EXPECT_EQ(line.count(line.algorithm("( 1.2 + 2.1 ) / 3")), 1.1);
    EXPECT_EQ(line.count(line.algorithm("1.1 * ( 1 + 1.1 )")), 2.31);
    EXPECT_EQ(line.count(line.algorithm("2.5 ^ 2")), 6.25);
}
