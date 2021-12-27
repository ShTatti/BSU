#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

class Calculator
{
public:
    int Priority(string s);
    bool NumberOfBrackets(const vector<string>& line);

    double Count(const string& final_line);
    string Algorithm();
    bool CorrectWord(const vector<string>& v);
    bool IsCorrect(const string& line);
};

