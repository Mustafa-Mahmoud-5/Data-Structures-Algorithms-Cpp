#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>    // std::max

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int data) {
        this->data =data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;
public:
    Node* getRoot() {
        return root;
    }

    BinaryTree(){
        root = nullptr;
    }

    void createTree() {
        Node* p; Node* t;
        queue<Node*> q;
        int x;
        cout << "Enter root node: " << flush; cin >> x;
        root = new Node(x);
        q.emplace(root);
        while(!q.empty()) {
            p = q.front();
            q.pop();
            cout << "Enter left node of " << p->data << ":" << flush; cin >> x;
            if(x != -1) {
                t = new Node(x);
                p->left = t;
                q.emplace(t);
            }
            cout << "Enter right node of " << p->data << ":" << flush; cin >> x;
            if(x != -1) {
                t = new Node(x);
                p->right = t;
                q.emplace(t);
            }
        }
    }

    void preorder(Node* n) {
        if(n) {
            cout << n->data << " ";
            preorder(n->left);
            preorder(n->right);
        }
    }

    void inorder(Node* n) {
        if(n) {
            inorder(n->left);
            cout << n->data << " ";
            inorder(n->right);
        }
    }

    void postOrder(Node* n) {
        if(n) {
            postOrder(n->left);
            postOrder(n->right);
            cout << n->data << " ";
        }
    }

    void levelOrder() {
        queue<Node*> q;
        Node * p;
        q.emplace(root);
        while(!q.empty()) {
            p = q.front();
            q.pop();
            if(p) {
                cout << p->data << " ";
                q.emplace(p->left);
                q.emplace(p->right);
            }
        }
    }

    void iterativePreOrder() {
        Node * p;
        p = root;
        stack<Node*> s;
        while(p || !s.empty()) {
            if(p) {
                cout << p->data << " ";
                s.emplace(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    void iterativeInOrder() {
        Node * p;
        p = root;
        stack<Node*> s;
        while(p || !s.empty()) {
            if(p) {
                s.emplace(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }

    }

    int height(Node* n) {
        if(!n) return -1; // 0-based idx; or just return 0 and make another function that calls this function and return its output - 1
        int x = height(n->left);
        int y = height(n->right);
        return 1 + max(x, y);
    }

    int nodesCount(Node* p) {
        if(!p) return 0;
        return nodesCount(p->left) + nodesCount(p->right) + 1;
    }
};


int main () {
    BinaryTree BT;
    BT.createTree();
    BT.preorder(BT.getRoot());
    cout << endl;
    BT.iterativePreOrder();
    cout << endl;
    cout << "Nodes Count: " << BT.nodesCount(BT.getRoot()) << endl;
    cout << "Tree Height: " << BT.height(BT.getRoot()) << endl;

}