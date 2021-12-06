#include <iostream>
#include <stdexcept>

template <class T>
class MyStack
{
private:
    T* m_array;
    int m_count;
    int m_max_size;
public:
    MyStack();
    inline MyStack(const MyStack<T> &rhs) { *this = rhs; }
    void operator=(const MyStack<T> &rhs);
    ~MyStack();
    void push(T data);
    void pop();
    void clear();
    bool empty() { return m_count == 0; }
    T& top() { return m_array[m_count - 1]; }
    int size() { return m_count; }
private:
    void init();
    void increase_array_size();
};

template <class T>
MyStack<T>::MyStack() : m_count(0), m_max_size(10) {
    init();
}

template <class T>
MyStack<T>::~MyStack() {
    delete [] m_array;
}

template <class T>
void MyStack<T>::init() {
    m_array = new T[m_max_size];
    m_count = 0;
}

template <class T>
void MyStack<T>::increase_array_size() {
    m_max_size = 2 * m_max_size;
    T* tmp = new T[m_max_size];
    for(int i = 0; i < m_count; i++){
        tmp[i] = m_array[i];
    }
    delete [] m_array;
    m_array = tmp;
}

template <class T>
void MyStack<T>::push(T data) {
    if(m_count == m_max_size)
        increase_array_size();
    m_array[m_count++] = data;
}

template <class T>
void MyStack<T>::pop() {
    if(m_count == 0)
        throw std::underflow_error("Underflow Exception!!!");
    m_count--;
}

template <class T>
void MyStack<T>::clear() {
    delete [] m_array;
    m_max_size = 10;
    init();
}

template <class T>
void MyStack<T>::operator=(const MyStack<T> &rhs) {
    if(this != &rhs) {
        delete [] m_array;
        init();
        for(int i = 0; i < rhs.m_count; i++) {
            this -> push(rhs.m_array[i]);
        }
    }
}