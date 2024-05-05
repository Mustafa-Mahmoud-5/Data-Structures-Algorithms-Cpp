#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }


    Node(int data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    DoublyLinkedList(int *A, int len) {
        if(len == 0) return;
        head = new Node(A[0]);

        Node* prev = head;

        for(int i = 1; i < len; i++) {
            Node* temp = new Node(A[i]); // data = A[i], prev = nullptr, next = nullptr
            temp->prev = prev;
            prev->next = temp;
            prev = temp;
        }
    }

    int length() {
        int c = 0;
        Node* p = head;
        while(p) {
            c++;
            p = p->next;
        }
        return c;
    }

    void display() {
        cout << "{";
        Node* p = head;
        while(p) {
            cout << " " << p->data;
            p = p->next;
        }
        cout << " }" << endl;
    }

    bool insertFirst(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }

    bool insertAtPosition(int pos, int val) {
        if(pos < 0 || pos > length()) {
            cout << "out of range";
            return false;
        }

        if(pos == 0) {
            return insertFirst(val);
        } else {
            Node* p = head;
            for(int i = 1; i <= pos-1; i++) {
                p = p->next;
            }
            Node* newNode = new Node(val);

            newNode->next = p->next;
            newNode->prev = p;
            if(p->next) p->next->prev = newNode;
            p->next = newNode;
            return true;
        }
    }

    bool removePosition(int pos) {
        if(pos < 1 || pos > length()) {
            cout << "out of range" << endl;
            return false;
        }


        if(pos == 1) {
            Node* temp = head;
            head = head->next;
            if(head) head->prev = nullptr;
            delete temp;
        } else {
            Node* p = head;
            for(int i = 1; i <= pos -1; i++) {
                p = p->next;
            }
            p->prev->next = p->next;
            if(p->next) p->next->prev = p->prev;
            delete p;
        }
        return true;
    }

    void reverse() {
        if(!head || !head->next) return;

        Node* p1 = head;
        Node* p2 = head->next;
        while(p1!= nullptr) {
            p1->next = p1->prev;
            p1->prev = p2; // p2 is p1->next TEMP AKA BEFORE setting it to prev

            if(!p1->prev) head = p1;

            p1 = p2;
            if(p2) p2 = p2->next;
        }
    }
};

int main() {
    DoublyLinkedList dll{};
    dll.insertFirst(20);
    dll.insertFirst(30);
    dll.insertFirst(40);
    dll.insertAtPosition(0, 10);
    dll.insertAtPosition(2, 45);
    dll.insertAtPosition(5, 80);
    dll.removePosition(1);
    dll.removePosition(3);
    dll.removePosition(4);
    dll.insertAtPosition(3, 90);
    dll.display();


    DoublyLinkedList dll2{};
    dll2.insertFirst(1);
    dll2.insertFirst(2);
    dll2.insertFirst(3);
    dll2.display();
    dll2.reverse();
    dll2.display();
}