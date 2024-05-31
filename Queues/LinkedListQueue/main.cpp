#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};


class Queue {
private:
    Node* first;
    Node* rear;
public:
    Queue() {
        first = rear = nullptr;
    }

    bool isEmpty() {
        if(!first) {
            return true;
        }
        return false;
    }

    int top() {
        int x = -1;
        if(first!=nullptr) {
             x= first->data;
        }
        return x;
    };

    void enqueue(int val) {
        if(isEmpty()) {
            first = rear = new Node(val);
        } else {
            rear->next = new Node(val);
            rear = rear->next;
        }
    }

    int dequeue() {
       int x = -1;
       if(!isEmpty()) {
           Node* t = first;
           x = t->data;
           first = first->next;
           delete t;
       }
       return x;
    }

    void display() {
        if(isEmpty()) {
            cout << "{ }" << endl;
        } else {
            Node* p = first;
            cout << "{ ";
            while(p) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << "}";
        }
    }



};
int main() {
    Queue q;
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
    return 0;
}
