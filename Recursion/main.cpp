#include <iostream>
using namespace std;

void calling(int n) {
    if (n > 0) {
        cout << n << endl;
        calling(n-1);
    }
}

void returning (int n) {
    if (n > 0) {
        returning(n-1);
        cout << n << endl;
    }
}


int staticValue(int n) {
    static int x = 0;
    if(n > 0) {
        x++;
        return staticValue(n-1) + x ;
    }
    return 0;
}

int main() {
    int x = 3;
    cout << "==Calling==" << endl;
    calling(x);
    cout << "==Returning==" << endl;
    returning(x);
    cout << "========================StaticValues in recursion===========" << endl;
    cout << staticValue(5) << endl;
    cout << staticValue(5) << endl;
}