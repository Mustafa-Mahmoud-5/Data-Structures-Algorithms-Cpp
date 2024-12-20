#include <iostream>
#include <stack>
#include <string>
using namespace std;

void displayStk(stack<int>stk) {
    cout << "{ ";
    while(!stk.empty()) {
        cout << stk.top()  << " ";
        stk.pop();
    }
    cout << "}" << endl;
}


bool isBalancedParentheses(string s) {
    stack <char> stk;
    for(int i = 0; i< s.size(); i++) {
        if(s[i] == '(') {
            stk.push('(');
        }
        if(s[i] == ')') {
            stk.pop();
        }
    }

    if(stk.empty()){
        return true;
    } else {
        return false;
    }
}

int evaluatePostfix(string s) {
    stack<int> stk;
    for(int i = 0; i < s.size(); i++) {
        int op1, op2;
        if(s[i] == '+') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();

            stk.push(op2+op1);
        } else if(s[i] == '-') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
            stk.push(op2-op1);
        } else if(s[i] == '*') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
            stk.push(op2*op1);
        } else if(s[i] == '/') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
            stk.push(op2/op1);
        } else {
            stk.push(s[i] - 48);
        }
        displayStk(stk);
    }
    return stk.top();
}


int main() {
    string s = "(a+ )b(*e-d))"; // false
    string s2 = "((a+b)*(b+c))";
    cout << "isBalanced: " << isBalancedParentheses(s) << endl;
    cout << "isBalanced: " << isBalancedParentheses(s2) << endl;




    string s3 = "6+5+3*4"; // brackets => (6+5)+(3*4) => sum => 11 + 12 = 23
    string s3Postfix = "65+34*+";
    cout << evaluatePostfix(s3Postfix) << endl;
}
