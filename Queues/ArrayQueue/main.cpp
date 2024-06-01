#include <iostream>
using namespace std;
// Linear Queue

// Implementation: front is one step before the first element of the Queue

class Queue {
private:
    int* Q;
    int front;
    int rear;
    int size; // capacity

public:

    Queue(int size) {
        this->Q = new int[size];
        this->front = this->rear = -1;
        this->size = size;
    }


    bool isEmpty() {
        if(this->front == this->rear) {
            return true;
        }
        return false;
    };

    bool isFull() {
        if(this->rear == this->size -1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        if(!isFull()) {
            this->Q[++this->rear] = x;
        } else {
            cout << "Overflow" << endl;
        }
    }

    int dequeue() {
        if(!isEmpty()) {
            this->front++;
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
            for(int i = this->front+1; i <= this->rear; i++) {
                cout << this->Q[i] << " ";
            }
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

// other implementations in which front is on the first element also exist, in this case,
// empty will be if front is -1 or if front is rear +1.
// is full will be if rear is size -1,
// enqueue will first check if front is -1, make it 0, then move rear one step and assign new element at new rear position.
// dequeue will move the front one-step
// printing will start from front to rear
// top is front