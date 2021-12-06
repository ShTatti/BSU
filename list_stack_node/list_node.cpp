#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int _v, Node* _n = nullptr): value(_v), next(_n){}
};

class List {
public:
    int size;
    Node* first;

    List(): size(0), first(new Node(0)) {}

    void insert(int value, int position) {
        Node* parent = first;
        for(;position;--position) {
            parent = parent->next;
        }
        insert(parent, value);
    }

    void insert(Node* parent, int value) {
        Node* newNode = new Node(value, parent->next);    // parent->next == (*parent).next
        parent->next = newNode;
        ++size;
    }

    bool remove(int value) {   //first founded, returns false if nothing removed
        Node* toRemove = first;
        while(toRemove->next != nullptr && toRemove->value != value) {
            toRemove = toRemove->next;
        }

        if (toRemove->next != nullptr) {
            return remove(toRemove);
        }

        return false;
    }

    bool remove(Node* node) {
        Node* nextNode = node->next;

        node->value = node->next->value;
        node->next = node->next->next;

        delete nextNode;
        --size;
        return true;
    }

    void print(std::ostream& out) {
        Node* cur = first;
        while (cur->next != nullptr) {
            out << cur->value << "  ";
            cur = cur->next;
        }
    }
};