#include <iostream>
#include <algorithm>

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


    
    // ------------Some Excercises------


    // 1-Write a function getMin (a member of BST), which gets the minimum value in the BST..

    int getMin(Node* n) {
        if(!n) return INT_MAX;
        int leftMin = getMin(n->left);
        int rightMin = getMin(n->right);
        int subMin = min(leftMin, rightMin);
        return min(n->data, subMin);
    }

    /*
// //2- Write a function getSum(a member of BST) that given a node value, it returns the sum of node values
// from the root to this node. For example given the value 9 in the given tree, the returned sum should be
// 27*/

    int getPathSum(int key) {
        Node* p = root;
        int s =  0;
        while(p) {
            s+=p->data;
            if(key == p->data) {
                return s;
            } else if(key < p->data) {
                p = p->left;
            } else {
                p=p->right;
            }
        }
        return -1; // first condition was not hit, key doesn't exist;
    }


    int getLevel(int key) {
        int level = 0;
        Node* p = root;
        while(p) {
            if(key == p->data) {
                return level;
            } else if(key < p->data) {
                p = p->left;
                level++;
            } else {
                p=p->right;
                level++;
            }
        }
        return -1;
    }


    int getNumNodes(Node* n) {
        if(!n) return 0;
        return getNumNodes(n->left)  + getNumNodes(n->right) + 1;
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

    cout << endl;



    BinarySearchTree bst_test;

    bst_test.insert(3);
    bst_test.insert(5);
    bst_test.insert(6);
    bst_test.insert(10);
    bst_test.insert(12);
    bst_test.insert(14);
    bst_test.insert(15);

    cout << "Min: " << bst_test.getMin(bst_test.getRoot()) << endl;
    cout << "Level: " << bst_test.getLevel(10) << endl;
    cout << "Path Sum: " << bst_test.getPathSum(10) << endl;
}