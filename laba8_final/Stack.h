#define SIZE 100

#include <iostream>

using namespace std;

template<typename T>
class Stack
{
private:
    string *arr;
    int capacity;
    int top;

public:
    Stack(int size = SIZE);
    int size();

    void push(const string& element);
    string pop();
    string peek();

    bool IsEmpty();
    bool IsFull();

    string &operator [] (int n);
    bool operator == (const Stack &st2);
    bool operator != (const Stack &st2);
    bool operator < (const Stack &st2);
    bool operator > (const Stack &st2);
    void operator << (double number);
    double operator >> (double &number);
    Stack& operator = (const Stack &massive);

    ~Stack();
};

template<typename T>
Stack<T>::Stack(int size) {
    arr = new string[size];
    capacity = size;
    top = -1;
}

template<typename T>
int Stack<T>::size() {
    return top + 1;
}
template<typename T>
void Stack<T>::push(const string& el) {
    if (IsFull()) {
        cout << "Stack is full" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        arr[++top] = el;
    }
}

template<typename T>
string Stack<T>::pop() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        return arr[top--];
    }
}

template<typename T>
string Stack<T>::peek() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        return arr[top];
    }
}

template<typename T>
bool Stack<T>::IsEmpty() {
    return top == -1;
}

template<typename T>
bool Stack<T>::IsFull() {
    return top == capacity - 1;
}

template<typename T>
string & Stack<T>::operator [] (int n) {
    if (n < 0 || n >= size()) {
        cout << "You can't use this index!" << endl;
    }
    cout << arr[n];
    return arr[n];
}

template<typename T>
bool Stack<T>::operator == (const Stack &st2) {
    for (int i = 0; i < size(); ++i)
    {
        if (this -> arr[i] == st2.arr[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

template<typename T>
bool Stack<T>::operator != (const Stack &st2) {
    for (int i = 0; i < size(); ++i) {
        if (this -> arr[i] != st2.arr[i]) {
            return true;
        }
        else {
            continue;
        }
    }
    return false;
}

template<typename T>
bool Stack<T>::operator < (const Stack &st2) {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size(); ++i) {
        sum1 += this -> arr[i];
        sum2 += st2.arr[i];
    }
    if (sum1 < sum2) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool Stack<T>::operator > (const Stack &st2) {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size(); ++i) {
        sum1 += this -> arr[i];
        sum2 += st2.arr[i];
    }
    if (sum1 > sum2) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
void Stack<T>::operator << (double num) {
    push(num);
}

template<typename T>
double Stack<T>::operator >> (double &num) {
    num = peek();
    this -> pop();
    return num;
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack &arr1) {
    this -> capacity = arr1.capacity;
    for (int i = 0; i < arr1.capacity; ++i) {
        this -> arr[i] = arr1.arr[i];
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] arr;
}