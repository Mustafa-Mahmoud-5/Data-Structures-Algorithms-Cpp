#include <iostream>
using namespace std;
// Circular Array Queue

// Implementation: front is one step before the first element of the Queue

class Queue {
private:
    int* Q;
    int front;
    int rear;
    int size; // capacity

public:

    Queue(int size) {
        this->Q = new int[size+1];
        this->front = this->rear = 0; // Front will always be empty
        this->size = size+1;
    }


    bool isEmpty() {
        if(this->front == this->rear) {
            return true;
        }
        return false;
    };

    bool isFull() {
        if((this->rear + 1) % this->size == this->front) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        if(!isFull()) {
            this->rear = ( this->rear + 1 )% this->size;
            this->Q[this->rear] = x;
        } else {
            cout << "Overflow" << endl;
        }
    }

    int dequeue() {
        if(!isEmpty()) {
            this->front = (this->front + 1) % this->size;
            int x = this->Q[this->front];
            return x;
        } else {
            cout << "Underflow" << endl;
            return -1;
        }
    }

    int top() {
        if(!isEmpty()) {
            return this->Q[this->front+1]; // notice that Front is one step before the Front in this Implementation
        } else {
            return -1;
        }
    }

    void display() {
        if(isEmpty()) {
            cout << "{ }" << endl;
        } else {

            cout << "{ ";
            int i = this->front + 1;
            do {
                cout << this->Q[i] << " ";
                i = (i + 1) % size;
            } while (i != (this->rear + 1) % size);

            cout << "}" << endl;
        }
    }
};

int main() {
    Queue q(5);
    cout << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // overflow
    q.dequeue();
    q.dequeue();
    cout << "Top: " << q.top() << endl;
    q.display();
}