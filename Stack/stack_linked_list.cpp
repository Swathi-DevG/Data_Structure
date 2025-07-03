#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = nullptr;
    }
};

class Stack{
    private:
    Node* top;

    public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if (top == nullptr) {
            cout<<"Stack is Empty\n";
            return true;
        }
        return false;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Nothing to Peek\n";
            return -1;
        }
        return top->data;
    }

    void push(int val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Nothing to pop\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    ~Stack() {
        while(!isEmpty()) {
            pop();
        }
        cout<<"Memory released\n";
    }
};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Peek: "<<s.peek()<<endl;
    s.pop();
    cout<<"Peek: "<<s.peek()<<endl;
    return 0;
}