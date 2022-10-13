// Programmers: Rick Mercer and Felipe Lopez

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

// Stack is an abstract class because it has all pure virtual
// functions.  This is the equivalent to a Java interface.
template<typename Type>
class Stack {
public:
    virtual void push(Type const &) = 0; // push element
    virtual Type pop() = 0; // return top element & remove
    virtual Type top() const = 0;  // return top el
    virtual bool isEmpty() const = 0;  // return true
};


/////////// VectorStack //////////////
template<class Type>
class VectorStack : Stack<Type> {

private:

    vector<Type> vecStack;

public:
    void push(Type const &element) override {
        vecStack.push_back(element);
    }

    Type pop() override {
        Type poppedValue = vecStack[vecStack.size() - 1];
        vecStack.erase(vecStack.end() - 1);
        return poppedValue;
    }

    Type top() const override {
        return vecStack[vecStack.size() - 1];
    }

    bool isEmpty() const override {
        if (vecStack.size() <= 0) {
            return true;
        }
        return false;
    }

    void printStack() {
        for (auto i: vecStack) {
            cout << i << endl;
        }
    }
};


//////////// ArrayStack //////////////
template<class Type>
class ArrayStack : Stack<Type> {
private:
    Type data[1000];
    int dataSize = 0;

public:

    void push(Type const &element) override {
        data[dataSize] = element;
        dataSize += 1;
    }

    Type pop() override {
        if (dataSize == 0) {
            return data[dataSize];
        } else {
            dataSize -= 1;
            return data[dataSize];
        }
    }

    Type top() const override {
        return data[dataSize - 1];
    }

    bool isEmpty() const override {
        if (dataSize <= 0) {
            return true;
        }
        return false;
    }

};


///////// LinkedStack
template<class Type>
class LinkedStack : Stack<Type> {

private:

    struct Node {
        Type data;
        Node *next;

        Node() {};

        Node(Type const &element) {
            data = element;
            next = nullptr;
        }

        Node(Type const &element, Node *nextRef) {
            data = element;
            next = nextRef;
        }
    };

    int linkedSize = 0;

    Node *first = new Node;


public:
    // You will get many errors until this implements the
    // four methods or the abstract class Stack<Type>
    void push(Type const &element) override {
        if (linkedSize == 0) {
            first = new Node(element);
        } else {
            first = new Node(element, first);
        }
        linkedSize += 1;
    }

    Type pop() override {
        Type poppedElement = first->data;
        if (linkedSize != 0) {
            first = first->next;
            linkedSize -= 1;
        }
        return poppedElement;
    }

    Type top() const override {
        return first->data;
    }

    bool isEmpty() const override {
        if (linkedSize == 0) {
            return true;
        }
        return false;
    }

};