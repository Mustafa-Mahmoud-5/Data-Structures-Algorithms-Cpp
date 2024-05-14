#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

};

class BinarySearchTree {
private:
    Node* root;
public:

    BinarySearchTree() {
        root = nullptr;
    }

    Node* getRoot() {
        return this->root;
    }


    void inorder(Node* n) {
        if(n) {
            inorder(n->left);
            cout << n->data << " ";
            inorder(n->right);
        }
    }


    //  lg(N+1) - 1  <= height <= n - 1
    //  perform n = height comparisons
    //  O(N) worst case if tree is skewed. O(lgn) best case if height = lgn.
    Node* search(int key) {
        Node* p = root;
        while(p) {
            if(key == p->data) {
                return p;
            } else if(key < p->data) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        return nullptr;
    }

    Node* recursiveSearch(Node* p, int key) {
        if(!p) return nullptr;
        if(key == p->data) {
            return p;
        } else if (key < p->data) {
            return recursiveSearch(p->left, key);
        } else {
            return recursiveSearch(p->right, key);
        }
    }

    // using tail pointer
    void insert(int key) {
        if(!root) {
            root = new Node(key);
            return;
        }

        Node* p = root;
        Node* q = nullptr; // tail pointer

        while(p) {
            if(key == p->data) {
                cout << "Can't insert duplicate keys" << endl;
                return;
            } else if(key < p->data) {
                q = p;
                p = p->left;
            } else {
                q = p;
                p = p->right;
            }
        }
        // q stopped at a leaf node

        if(key < q->data) {
            q->left = new Node(key);
        } else {
            q->right = new Node(key);
        }
    }

    // by pre-checking for next(left/right) element
    void insert2(int key) {
        if(!root) {
            root = new Node(key);
            return;
        }


        Node* p = root;
        while(true) {
            if(key == p->data) {
                cout << "Can't insert duplicate keys" << endl;
                return;
            } else if(key > p->data) {
                if(p->right) {
                    p = p->right;
                } else {
                    Node* newNode = new Node(key);
                    p->right = newNode;
                    return;
                }
            } else {
                if(p->left) {
                    p = p->left;
                } else {
                    Node *newNode = new Node(key);
                    p->left = newNode;
                    return;
                }
            }
        }
    }


    // by creating new node once we reach null node
    Node* recursiveInsert(Node* p, int key) {

        if(!root) {
            root = new Node(key);
            return root;
        }
        // we reached null child, create new Node return it so we assign it to the previous node which is the correct place to insert at.
        if(!p) {
            Node* t = new Node(key);
            return t;
        }

        if(key < p->data) {
            p->left = recursiveInsert(p->left, key);
        } else if(key > p->data) {
            p->right = recursiveInsert(p->right, key);
        }

        return p;
    }

    // by pre-checking for next(left/right) element and recursively repeat inside the left/right subtree
    void recursiveInsert2(Node* p, int key) {
        if(!root) {
            root = new Node(key);
            return;
        } else if(p->data == key) {
            cout << "Can't insert duplicate keys" << endl;
        } else if(key < p->data) {
            if(p->left) {
                recursiveInsert(p->left, key);
            } else {
                Node* t = new Node(key);
                p->left = t;
            }
        } else {
            if(p->right) {
                recursiveInsert(p->right, key);
            } else {
                Node* t = new Node(key);
                p->right = t;
            }
        }
    }

    Node* Delete(Node *p, int key) {
        Node* q;

        if (p == nullptr){
            return nullptr;
        }

        if (p->left == nullptr && p->right == nullptr){
            if (p == root){
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (key < p->data){
            p->left = Delete(p->left, key);
        } else if (key > p->data){
            p->right = Delete(p->right, key);
        } else {
            if (Height(p->left) > Height(p->right)){
                q = InPre(p->left);
                p->data = q->data;
                p->left = Delete(p->left, q->data);
            } else {
                q = InSucc(p->right);
                p->data = q->data;
                p->right = Delete(p->right, q->data);
            }
        }
        return p;
    }

    int Height(Node *p) {
        int x;
        int y;
        if (p == nullptr){
            return 0;
        }
        x = Height(p->left);
        y = Height(p->right);
        return x > y ? x + 1 : y + 1;
    }

    Node* InPre(Node *p) {
        while (p && p->right != nullptr){
            p = p->right;
        }
        return p;
    }

    Node* InSucc(Node *p) {
        while (p && p->left != nullptr){
            p = p->left;
        }
        return p;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(8);
    bst.insert(3);
    bst.insert(4);
    bst.insert(1);
    bst.insert(9);
    bst.insert(6);
    bst.insert(6); // duplicate
    bst.inorder(bst.getRoot());
    cout << endl;


    BinarySearchTree bst2;

    bst2.recursiveInsert(bst2.getRoot(), 5);
    bst2.recursiveInsert(bst2.getRoot(), 8);
    bst2.recursiveInsert(bst2.getRoot(), 3);
    bst2.recursiveInsert(bst2.getRoot(), 4);
    bst2.recursiveInsert(bst2.getRoot(), 1);
    bst2.recursiveInsert(bst2.getRoot(), 9);
    bst2.recursiveInsert(bst2.getRoot(), 6);

    bst2.inorder(bst2.getRoot());
}