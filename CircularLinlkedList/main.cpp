#include <iostream>
using  namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class CircularSinglyLinkedList {
private:
    Node* head;
public:

    Node* getHeadPointer() {
        return this->head;
    }
    void display() {
        if(!head) {
            cout << "{ }" << endl;
            return;
        }
        Node* p = head;
        cout << "{";
        do {
            cout << " " << p->data;
            p = p->next;
        } while(p && p!= head);
        cout << " }" << endl;
    }

    void recursiveDisplay(Node* p) {
        static bool isMoved = false;

        if(!isMoved && p == head) {
            cout << "{"; // will be called at the first call in the calling phase
        }
        if(isMoved && p == head) {
            cout << " }" << endl; // will be called at the last call in the returning phase
        }

        if(!isMoved || p!= head) {
            isMoved = true;
            cout << " " << p->data;
            recursiveDisplay(p->next);
        }

        isMoved = true; // will be called with every call in the returning phase
    }

    int length() {
        int c = 0;
        if(!head) return 0;
        Node* p = head;
        do {
            c++;
            p = p->next;
        } while (p && p != head);
        return c;
    }

    bool insertAtFront(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = newNode;
            head->next = head;
            return true;
        } else {

            Node*p = head;

            while(p && p->next != head) {
                p = p->next;
            }

            newNode->next = head;
            head = newNode;
            p->next = head;
            return true;
        }
    }

    bool insertAtPosition(int pos, int val) {
        if(pos < 0 || pos > length()) {
            cout << "out of range" << endl;
            return false;
        }

        if(pos == 0) {
            return insertAtFront(val);
        } else {
            // insert at any position
            Node *p = head;
            for(int i = 1; i <= pos -1; i++) {
                p = p->next;
            }
            Node* newNode =  new Node(val);
            newNode->next = p->next;
            p->next = newNode;
            return true;
        }

    }

    bool removeFromPosition(int pos) {
        cout << "CURRLENGHT: " << length() << endl;
        if(pos < 1 || pos > length()) {
            cout << "out of range" << endl;
            return false;
        }

        if(pos == 1) {
            Node *p = head;
            while(p && p->next != head) {
                p = p->next;
            }
            Node* first = head;
            head = head->next;
            p->next = head;
            delete first;
            return true;
        } else {
            Node* q = nullptr;
            Node* p = head;
            for(int i = 1; i <= pos - 1; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
            return true;
        }
    }

};

int main() {
    CircularSinglyLinkedList csll{};
    cout << csll.length() << endl;
    csll.display();
    csll.insertAtFront(50);
    csll.insertAtFront(40);
    csll.insertAtFront(80);
    csll.display();
    csll.display();
    cout << csll.length() << endl;
    csll.removeFromPosition(1);
    csll.insertAtFront(60);
    csll.removeFromPosition(3);
    csll.display();

    CircularSinglyLinkedList csll2{};
    csll2.insertAtPosition(0, 10);
    csll2.insertAtPosition(1, 12);
    csll2.insertAtPosition(2, 10);
    csll2.display();
    csll2.recursiveDisplay(csll2.getHeadPointer());
}