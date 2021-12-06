#include "stack_array.h"
#include <iostream>

using namespace std;

int main()
{
    MyStack<int> stack;
    int sum = 0;

    for(int i = 0; i < 15; i++)
        stack.push(i);

    while(!(stack.empty())) {
        sum += stack.top();
        stack.pop();
    }

    cout << "sum: " << sum << endl;

    stack.push(10);
    stack.push(20);

    stack.top() -= 5;

    cout << "stack.top() is now " << stack.top() << endl;

    MyStack<char> stack2;

    stack2.push('t');
    stack2.push('s');
    stack2.push('e');
    stack2.push('T');

    while(!(stack2.empty())) {
        cout << stack2.top();
        stack2.pop();
    }
    cout << endl;

    stack2.push('A');
    stack2.push('B');
    stack2.push('C');

    stack2.clear();

    stack2.push('D');
    stack2.push('E');
    stack2.push('F');

    while(!(stack2.empty())) {
        cout << stack2.top();
        stack2.pop();
    }
    cout << endl;

}