#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }

     Node(int data, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }

};


class SinglyLinkedList {
private:
    Node* head;


public:

    Node* getHeadPointer() {
        return head;
    }

    bool insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = newNode;
        } else {
            cout << "HERE" << endl;
            newNode->next = head;
            head = newNode;
        }
        return true;
    }

    bool insertAtPosition(int pos, int val) {
        if(pos < 0 || pos > length()) {
            cout << "out of range" << endl;
            return false;
        }

        if(pos == 0) {
            insertAtFirst(val);
        } else {
            Node* p = head;
            for(int i = 1; p && i <= pos - 1; i++) {
                p = p->next;
            }

            Node* newNode = new Node(val);
            newNode->next = p->next;
            p->next = newNode;
        }

        return true;

    }

    bool removeFromPosition(int pos) {
        if(pos < 1 || pos > length()) {
            cout << "out of range" << endl;
            return false;
        }

        if(pos == 1) {
            if (!head) {
                return false;
            } else {
                Node *p = head;
                head = head->next;
                delete p;
                return true;
            }
        } else {
            Node* p = head;
            Node* q = nullptr;
            for(int i = 1; i <= pos - 1 && p; i++) {
                q = p;
                p = p->next;
            }

            q->next = p->next;
            delete p;
            return true;
        }
    }

    bool insertSorted(int val) {
        if(!head) {
            head = new Node(val);
            return true;
        }
        Node* q = nullptr; // this will be the pointer pointing to the node before the newNode
        Node* p = head; // to compare if current node is smaller, then we stop at it and insert newNode before it
        Node* newNode = new Node(val);
        while(p && val > p-> data) {
            q = p;
            p = p->next;
        }
        if(p == head) {
            newNode->next = head;
            head = newNode;
        } else {
            q->next = newNode;
            newNode->next = p;
        }
        return true;
    }

    bool isSorted() {
        if(!head) {
            return true;
        }

        Node* p = head;
        while(p->next) {
            if(p->data  > p->next->data) {
                return false;
            }
            p = p->next;
        }
        return true;
    }

    void removeDuplicatesFromSortedList() {
        if(!head || !head-> next) return;
        Node* q = head;
        Node* p = head->next;
        while(p) {
            if(q->data == p->data) {
                // remove p
                q->next = p->next;
                delete p;
                p = q->next;
            } else {
                q = p;
                p = p->next;
            }
        }

    }

    void display() {
        Node* p = head;
        cout << "{ ";
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "}" << endl;
    }

    void recursiveDisplay(Node* p) {
        if(p == head) {
            cout << "{ ";
        }
        if(!p) {
            cout << "}" << endl;
            return;
        } else {
            cout << p->data << " ";
            recursiveDisplay(p->next);
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

    int sum() {
        int s = 0;
        Node* p = head;
        while(p) {
            s+= p->data;
            p = p->next;
        }
        return s;
    }

    int recursiveSum(Node* p) {
        if(!p) {
            return 0;
        } else {
            return p->data + recursiveSum(p->next);
        }
    }

    int max() {
        if(!head) return -1;
        Node* p = head;
        int max = p->data;
        while(p) {
            if(p->data > max) {
                max= p->data;
            }
            p = p->next;
        }
        return max;
    }

    Node* search(int val) {
        Node* p = head;
        while(p) {
            if(p->data == val) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    Node* recursiveSearch(Node* p, int val) {
        if(!p) return nullptr;
        if(p->data == val) {
            return p;
        } else {
            return recursiveSearch(p->next, val);
        }
    }

    void concatenate(Node* secondHead) {
        // get last node and set its next to the second
        if(!head) {
            head = secondHead;
            return;
        }
        Node* p = head;
        while(p) {
            p = p->next;
        }
        p->next = secondHead;
    }

    // Sliding Window technique
    void reverse() {
        if(!head) return;
        Node* p1 = nullptr; // this will keep the previous Node
        Node* p2 = head; // this will change next to previous
        Node* p3 = p2->next; // this will be a temp pointer pointing to p2 -> next so that after setting p2->next = p1. we can still move p2 to p2->next(which is p3)
        while(p2) { // loop over the entire list, stop when p2(which is reposnsible for changing next) is null, then p1 will point at the end
            p2->next = p1; // set the pointer to the previous

            p1 = p2;
            p2 = p3;
            if(p3) p3 = p3->next;
        }
        head = p1; // set head to the node pointing at the last node which is p1
    }

    void recursiveReverse(Node* prev, Node* curr) {
        if(curr) {
            recursiveReverse(curr, curr->next);
            curr->next = prev;
        } else {
            head = prev;
        }
    }

    ~SinglyLinkedList() {
        Node* p = head;
        Node* q = nullptr;

        while(p) {
            q = p;
            p = p->next;
            delete q;
        }
    }

};

int main() {
    SinglyLinkedList sll{};
    sll.insertAtFirst(50);
    sll.insertAtFirst(70);
    sll.display();
    sll.recursiveDisplay(sll.getHeadPointer());

    cout << sll.sum() << endl;
    cout << sll.recursiveSum(sll.getHeadPointer()) << endl;

    cout << sll.max() << endl;



    sll.insertAtPosition(3, 200);
    sll.display();
    sll.removeFromPosition(2);
    sll.removeFromPosition(1);
    sll.insertAtFirst(90);
    sll.display();


    SinglyLinkedList sortedSll{};
    sortedSll.insertSorted(10);
    sortedSll.insertSorted(7);
    sortedSll.insertSorted(8);
    sortedSll.insertSorted(9);
    sortedSll.insertSorted(6);
    sortedSll.insertSorted(8);
    sortedSll.insertSorted(10);
    sortedSll.display();
    cout << sortedSll.isSorted() << endl;

    sortedSll.removeDuplicatesFromSortedList();
    sortedSll.display();
    sortedSll.recursiveReverse(nullptr, sortedSll.getHeadPointer());
    sortedSll.display();
}