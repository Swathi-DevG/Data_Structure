#include <iostream>
#include <cstring>

using namespace std;

class Stack {
    public:
    int top;
    int maxSize;
    char *arr;

    Stack (int size) {
        top = -1;
        maxSize = size;
        arr = new char[size];
    }

    bool isFull() {
        if(top == maxSize - 1) return true;
        else return false;
    }

    bool isEmpty() {
        if(top == -1) return true;
        else return false;
    }

    char peek() {
        if(!isEmpty()) return arr[top];
        else {
            cout<<"Error: Empty stack\n";
            return 0;
        }
    }

    void push(char data) {
        if(isFull()) {
            cout<<"Error: Stack is Full\n";
            return;
        }
        top++;
        arr[top] = data;
        return;
    }

    char pop() {
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

bool isOperand(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return true;
    }
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    if(ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

int ispredence(char ch) {
    switch(ch) {
        case '%':
        return 1;
        case '*':
        return 1;
        case '/':
        return 1;
        case '+':
        return 0;
        case '-':
        return 0;
    }
    return -1;
}

void infix_to_postfix(char *arr) {
    Stack s(20);
    char out[20] = "";
    int i=0;
    int ind = 0;
    while(arr[i]) { 
        if(isOperand(
            arr[i])) {
            out[ind++] += arr[i];
        }
        else if(arr[i] == '(') {
            s.push(arr[i]);
        }
        else if(arr[i] == ')') {
            while(s.peek() != '(' && !s.isEmpty()) {
                out[ind++] += s.pop();
            }
            if (!s.isEmpty()) s.pop(); 
        }
        else {
            while(!s.isEmpty() && s.peek()!= '(' && ispredence(s.peek()) >= ispredence(arr[i])) {
                out[ind++] += s.pop();
            }
            s.push(arr[i]);
        }
        i++;
    }
    while(!s.isEmpty()) {
        out[ind++] += s.pop();
    }
    cout<<"Postfix: "<<out<<endl;
}
int main() {
    char arr[20];
    scanf("%s",arr);

    infix_to_postfix(arr);
    return 0;

}

