#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int karatsuba(int x, int y) {
    // T(n) = 3T(n/2) + O(n)
    // O(n^log₂3) = O(n^1.585)
    if (x < 10 || y < 10) return x*y;
    int len = max(to_string(x).size(), to_string(y).size());
    int half  = len  / 2;
    int divisor = pow(10, half);
    int a = x / divisor;
    int b = x % divisor;
    int c = y / divisor;
    int d = y % divisor;

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int apb_cpd = karatsuba(a+b, c+d);
    return (pow(10, len) * ac) + (pow(10, half) * (apb_cpd - ac - bd)) + bd;
}


int main() {
    int x = 1231; // x = 10^2 x 12 + 31   => 10^2 a + b
    int y = 2112; // y = 10^2 x 21 + 12   => 10^2 c + d
    //    x.y = 10^n(ac) +  10^(n/2) x (ad)+(bc) + bd
    //    we need only 3 recursive calls because:
    //    (a+b)(c+d) = ac + bc+ad + bd
    //    ad+bc  = (a+b)x(c+d) - ac - bd
    //    since we already compute ac and bd.. now we just need a third recursive call for (a+b)(c+d)
    //    and then subtract it from ac and bd to get ad+bc

    cout << karatsuba(x,y) << endl;
}
