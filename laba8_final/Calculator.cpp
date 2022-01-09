#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <complex>

using namespace std;

bool isNumber(char a){
  return (a >= '0'&& a <='9') || a == '.' || a ==' ';
}
bool isBracket(char a){
  return a == '(' || a == ')';
}
string newStringWithPr(const string str) {
  string answer;
  int p = 0;
  answer.push_back(str[0]);
  for (int i = 1; i < str.size(); i++) {
    switch (p) {
      case 0: // число
        if (isNumber(str[i])) {
          p = 0;
          answer.push_back(str[i]);
        }
        if(isBracket(str[i])){
          p = 3;
          answer.push_back(' ');
          answer.push_back((str[i]));
          break;
        }
        if (!isNumber(str[i])) {
          p = 1;
          answer.push_back(' ');
          answer.push_back((str[i]));
        }
        break;
      case 1: // оператор
        if (isNumber(str[i])) {
          p = 0;
          answer.push_back(' ');
          answer.push_back(str[i]);
        }
        if(isBracket(str[i])){
          p = 3;
          answer.push_back(' ');
          answer.push_back((str[i]));
          break;
        }
        if (!isNumber(str[i])) {
          p = 1;
          answer.push_back(' ');
          answer.push_back((str[i]));
          if (str[i] == '-') {
            p = 2;
          }
        }
        break;
      case 2: // minus
        if (isNumber(str[i])) {
          p = 0;
          answer.push_back(str[i]);
        }
        if(isBracket(str[i])){
          p = 3;
          answer.push_back(' ');
          answer.push_back((str[i]));
          break;
        }
        if (!isNumber(str[i])) {
          p = 1;
          answer.push_back(' ');
          answer.push_back((str[i]));
          if (str[i] == '-') {
            p = 2;
          }
        }
        break;
      case 3:
        if (isNumber(str[i])) {
          p = 0;
          answer.push_back(' ');
          answer.push_back(str[i]);
        }
        if(isBracket(str[i])){
          p = 3;
          answer.push_back(' ');
          answer.push_back((str[i]));
          break;
        }
        if (!isNumber(str[i])) {
          p = 1;
          answer.push_back(' ');
          answer.push_back((str[i]));
        }
    }
  }
  return answer;
}

int Calculator::Priority(string s) {
  if ((s == "(") || (s == ")")) {
    return 0;
  }
  if ((s == "+") || (s == "-")) {
    return 1;
  }
  if ((s == "*") || (s == "/")) {
    return 2;
  }
  if (s == "^") {
    return 3;
  }
  return -1;
}

bool Calculator::NumberOfBrackets(const vector<string> &line) {
  int num1 = 0, num2 = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == ")") {
      num1++;
    }
    if (line[i] == "(") {
      num2++;
    }
  }
  if (num1 == num2) {
    return true;
  } else {
    return false;
  }
}

bool Calculator::CorrectWord(const vector<string> &v) {
  for (int i = 0; i < v.size(); ++i) {
    string word = v[i];
    if ((isdigit(*word.begin())) || ((*word.begin() == '-') && (isdigit(*(word.end() - 1))))) {
      for (int j = 0; j < word.size() - 1; ++j) {
        if (!isdigit(word[j + 1])) {
          if ((word[j + 1] == '.') && (j + 1 != v.size() - 1)) {
            for (int k = j + 2; k < word.size(); ++k) {
              if (word[k] == '.') {
                return false;
              }
            }
          } else {
            return false;
          }
        }
      }
    } else {
      char el = *word.begin();
      if ((el == ')') || (el == '(') || (el == '+') || ((el == '-') && (!isdigit(*(word.end() - 1)))) || (el == '*')
          || (el == '/') || (el == '^')) {
        if (word.size() != 1) {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}

bool Calculator::IsCorrect(const string &line) {
  vector<string> v1;
  stringstream ss;
  ss << line;
  string temp;
  while (ss >> temp) {
    v1.push_back(temp); //emplace_back
  }

  for (int i = 0; i < v1.size(); ++i) {
    if (((isdigit(*(--v1[i].end()))) && ((!isdigit(*(v1[i].begin()))) && (*v1[i].begin() != '-')) ||
        ((!isdigit(*(--v1[i].end()))) && (isdigit(*(v1[i].begin())))))) {
      return false;
    }
  }

  for (int i = 0; i < v1.size() - 1; ++i) {
    if (((v1[i] == "(") && (v1[i + 1] == ")")) || ((v1[i] == ")") && (v1[i + 1] == "("))) {
      return false;
    }
    if ((isdigit(*(--v1[i].end()))) && ((v1[i + 1] == "(") || (isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == "*") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == "/") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == "+") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if (((v1[i] == "-") && (!isdigit(*(--v1[i].end())))) && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == "^") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == "(") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
    if ((v1[i] == ")") && ((v1[i + 1] == "(") || (isdigit(*(--v1[i + 1].end()))))) {
      return false;
    }
  }

  if (!NumberOfBrackets(v1)) {
    return false;
  }

  if (!CorrectWord(v1)) {
    return false;
  }

  if ((!isdigit(*(--v1[v1.size() - 1].end()))) && (v1[v1.size() - 1] != ")") && (v1[v1.size() - 1] != "(")) {
    return false;
  }

  return true;
}

string Calculator::Algorithm() {
  Stack<char> a;
  string line;
  string final_line;
  cout << "Enter a string:" << endl;
  getline(cin, line);
  string s = newStringWithPr(line);
  if (!IsCorrect(s)) {
    throw invalid_argument("Invalid");
  }
  stringstream x;
  x << line;
  vector<string> v1;
  stringstream ss;
  ss << s;
  string temp;
  while (ss >> temp) {
    v1.emplace_back(temp);
  }

  int i = 0;
  while (i < v1.size()) {
    if (v1[i] == " ") {
      final_line += v1[i];
      final_line += " ";
      i++;
      continue;
    }
    if ((v1[i] != " ") && (v1[i] != "(") && (v1[i] != ")") && (v1[i] != "+")
        && (v1[i] != "-") && (v1[i] != "*") && (v1[i] != "/") && (v1[i] != "^")) {
      final_line += v1[i];
      final_line += " ";
      i++;
      continue;
    }
    if (v1[i] == "(") {
      a.push("(");
      i++;
      continue;
    }
    if (v1[i] == ")") {
      while (a.peek() != "(") {
        if (!a.IsEmpty()) {
          final_line += a.peek();
          final_line += " ";
          a.pop();
          continue;
        }
      }
      if (a.peek() == "(") {
        if (!a.IsEmpty()) {
          a.pop();
          i++;
          continue;
        }
      }
    }

    if ((v1[i] == "*") || (v1[i] == "+") || (v1[i] == "-")
        || (v1[i] == "/") || (v1[i] == "^")) {
      if ((Priority(v1[i])) == 1) {
        if (!a.IsEmpty()) {
          while ((!a.IsEmpty()) && ((Priority(v1[i])) <= (Priority(a.peek())))) {

            final_line += a.peek();
            final_line += " ";
            a.pop();
            if (a.IsEmpty()) {
              break;
            }
          }
          a.push(v1[i]);
          i++;
          continue;
        }
        a.push(v1[i]);
        i++;
        continue;
      }
      if (((Priority(v1[i])) == 2) || ((Priority(v1[i])) == 3)) {
        if (!a.IsEmpty()) {
          while ((!a.IsEmpty()) && (Priority(a.peek()) >= (Priority(v1[i])))) {
            if (!a.IsEmpty()) {
              final_line += a.peek();
              final_line += " ";
              a.pop();
              continue;
            }
          }
        }
        a.push(v1[i]);
        i++;
        continue;
      }
    }
  }

  while (!a.IsEmpty()) {
    final_line += a.peek();
    final_line += " ";
    a.pop();
  }

  final_line.pop_back();
  return final_line;
}

double Calculator::Count(const string &line) {
  Stack<char> st;
  int i = 0;
  string word;
  stringstream x;
  x << line;
  while (x >> word) {
    if (isdigit(*(--word.end()))) {
      st.push(word);
      i++;
      continue;
    }
    if ((word == "*") || (word == "+") || (word == "-") || (word == "/") || (word == "^")) {
      if (!st.IsEmpty()) {
        double first = stod(st.pop());
        double second;
        if (st.size() == 0) {
          second = 0;
        } else {
          second = stod(st.pop());
        }
        if (word == "*") {
          double third = first * second;
          stringstream ss;
          ss << third;
          string s(ss.str());
          st.push(s);
          i++;
          continue;
        }
        if (word == "+") {
          double third = first + second;
          stringstream ss;
          ss << third;
          string s(ss.str());
          st.push(s);
          i++;
          continue;
        }
        if (word == "/") {
          if (first == 0) {
            throw invalid_argument("Division by zero!!!");
          } else {
            double third = (double) second / first;
            stringstream ss;
            ss << third;
            string s(ss.str());
            st.push(s);
            i++;
            continue;
          }
        }
        if (word == "-") {
          double third = second - first;
          stringstream ss;
          ss << third;
          string s(ss.str());
          st.push(s);
          i++;
          continue;
        }
        if (word == "^") {
          double third = pow(second, first);
          stringstream ss;
          ss << third;
          string s(ss.str());
          st.push(s);
          i++;
          continue;
        }
      }
    }
  }
  cout << "Result: " << stod(st.peek()) << endl;
  return stod(st.peek());
}