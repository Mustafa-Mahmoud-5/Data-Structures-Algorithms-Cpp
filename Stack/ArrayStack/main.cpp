#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* s;
    int size;
public:
    Stack(int size){
        this->size = size;
        this->s = new int[size];
        this->top = -1;
    }

    bool isEmpty() {
        if(top == -1) return true;
        return false;
    }

    bool isFull() {
        if(top == size-1) return true;
        return false;
    };

    void push(int val) {
        if(!isFull()) {
            s[++top] = val;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        int x = -1;
        if(!isEmpty()) {
            x = s[top--];
        } else {
            cout << "Stack Underflow" << endl;
        }
        return x;
    }



    int peak(int pos) {
        // target = top - position + 1;
        int x = -1;
        int target = top - pos + 1;
        if(target) {
            x = s[target];
        }
        return x;
    }

    void display() {
        cout << "{ ";
        for(int i = top; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << "}" << endl;
    }
};


int main() {
    Stack s(5);
    cout << "Empty: " << s.isEmpty() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // overflow
    s.pop();
    s.display();
}
