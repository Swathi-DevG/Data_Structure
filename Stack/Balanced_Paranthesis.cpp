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

bool isBalanced_Paranthesis(char *arr) {
    Stack s(20);
    int i = 0;
    while(arr[i]) {
        if (arr[i]=='(' || arr[i]=='{' || arr[i] == '[') {
            s.push(arr[i]);
        }
        else if(arr[i]==')' || arr[i]=='}' || arr[i] == ']') {
            if(s.isEmpty()) return false;
            char open = s.pop();
            bool case1 = arr[i] == ')' && open != '(';
            bool case2 = arr[i] == '}' && open != '{';
            bool case3 = arr[i] == ']' && open != '[';
            if(case1 || case2 || case3) return false;
        }
        i++;
    }
    return s.isEmpty();
}

int main() {
    char arr[20];
    scanf("%s",arr);

    if (isBalanced_Paranthesis(arr)) {
        cout<<"Balanced Paranthesis\n";
    }
    else {
         cout<<"Not Balanced Paranthesis\n";
    }
    return 0;

}

