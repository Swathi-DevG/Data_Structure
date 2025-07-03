#include <iostream>
using namespace std;

class Stack {
    public:
    int top;
    int maxSize;
    int *arr;

    Stack (int size) {
        top = -1;
        maxSize = size;
        arr = new int[size];
    }

    bool isFull() {
        if(top == maxSize - 1) return true;
        else return false;
    }

    bool isEmpty() {
        if(top == -1) return true;
        else return false;
    }

    int peek() {
        if(!isEmpty()) return arr[top];
        else {
            cout<<"Error: Empty stack\n";
            return 0;
        }
    }

    void push(int data) {
        if(isFull()) {
            cout<<"Error: Stack is Full\n";
            return;
        }
        top++;
        arr[top] = data;
        return;
    }

    int pop() {
        if(isEmpty()) {
            cout<<"Error: Stack is Empty\n";
            return -1;
        }
        return arr[top--];
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Peek: "<<s.peek()<<endl;
    s.pop();
    cout<<"Peek: "<<s.peek()<<endl;
}

