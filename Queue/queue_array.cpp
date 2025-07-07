#include <iostream>
using namespace std;

class Queue {
    public:
    int front, rear;
    unsigned int size, capacity;
    int *arr;

    Queue(unsigned int capacity) {
        this->capacity = capacity;
        size = 0;
        rear = 0;
        front = -1;
        arr = new int[capacity];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void Enqueue(int data) {
        if (isFull()) {
            cout<<"Error: Queue is Full\n";
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
        return;
    } 

    int Dequeue() {
        if (isEmpty()) {
            cout<<"Error: Queue is empty\n";
            return '\0';
        }
        int val = arr[front];
        front = (front+1) % capacity;
        return arr[front];
    }

    int front_peek() {
        if (isEmpty()) {
            cout<<"Error: Queue is empty\n";
            return '\0';
        }
        return arr[front];
    }
    
    int rear_peek() {
        if (isEmpty()) {
            cout<<"Error: Queue is empty\n";
            return '\0';
        }
        return arr[front];
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(3);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    return 0;
}