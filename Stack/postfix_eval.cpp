#include <iostream>
#include <cstring>

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

bool isNum(char ch) {
    if(ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

int operation(int x, int y, char ch) {
    switch(ch) {
        case '%':
        return (x%y);
        case '*':
        return (x*y);
        case '/':
        return (x/y);
        case '+':
        return (x+y);
        case '-':
        return (x-y);
    }
    return -1;
}

void postfix_eval(char *arr) {
    Stack s(20);
    int i=0;
    int res = 0;
    while(arr[i]) {
        if(isNum(arr[i])) {
            int num = arr[i] - '0';
            s.push(num);
        }
        else {
            int val1 = s.pop();
            int val2 = s.pop();
            cout<<"val1 = "<<val1<<" val2 = "<<val2<<endl;
            res = operation(val2, val1, arr[i]);
            s.push(res);
        }
        i++;
    }
    cout<<"Evaluated result: "<<s.pop()<<endl;
}
int main() {
    char arr[20];
    scanf("%s",arr);

    postfix_eval(arr);
}

