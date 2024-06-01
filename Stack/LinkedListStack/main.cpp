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


class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if(top == nullptr) return true;
        return false;
    }


    void push(int val) {
        if(isEmpty()) {
            top = new Node(val);
        } else {
            Node* t = new Node(val);
            t->next = top;
            top = t;
        }
    }

    int pop() {
       int x = -1;
       if(!isEmpty()) {
            Node* t = top;
            top = top->next;
            x = t->data;
            delete t;
       } else {
           cout << "Stack Underflow" << endl;
       }
       return x;
    }

    int peak(int pos) {
        int x = -1;
        // move pos -1 steps because we start already from top;
        Node* p = top;
        for(int i = 0; p && i < pos-1; i++) {
            p = p->next;
        }
        if(p) {
            x = p->data;
        }
        return x;
    }

    void display() {
        Node* p = top;
        cout << "{ ";
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "}" << endl;
    }
};


int main() {
    Stack s;
    cout << "Empty: " << s.isEmpty() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.display();

    cout << "Peak: " << s.peak(3) << endl; // gives 30
    cout << "Peak: " << s.peak(10) << endl; // gives -1
}
