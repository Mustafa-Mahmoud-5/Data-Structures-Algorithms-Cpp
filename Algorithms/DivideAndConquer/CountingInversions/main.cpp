// GROUP:   X
// ID:      XXXXXXXX
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    XXX MY FULL NAME

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long MergeAndCount(long long* a, long long* aux, int l, int m, int h) {
    int c = 0;

    for(int k = l; k <= h; k++) {
        aux[k] = a[k];
    }

    int i = l;
    int j = m+1;
    for(int k = l; k <= h; k++) {
        if(i > m) {
            a[k] = aux[j++];
        } else if(j > h) {
            a[k] = aux[i++];
        } else if(aux[i] <= aux[j]) {
            a[k] = aux[i++];
        } else {
            // relying on the fact that the left arr is sorted, the right arr is sorted..
            // if an element from the left is greater than an element from the right..
            // then all subsequent elements from the left are for sure greater than all the elements from the right..
            // so we found mid-l+1 inversions
            a[k] = aux[j++];
            c += (m-i + 1);
        }
    }
    return c;
}
long long CountInv(long long* a, long long* aux, int l, int r) {
    // T(n) = 2T(n/2) + o(n) => O(nlogn)
    if(l<r) {
        int mid = (l+r) / 2;
        int lSplit = CountInv(a, aux, l, mid);
        int rSplit = CountInv(a, aux, mid+1, r);
        int inversionSplit = MergeAndCount(a, aux, l, mid, r);
        return lSplit + rSplit + inversionSplit;
    }
    return 0; // if only one element in the range
}

long long CountInvMerge(long long* a, int n) {
    long long aux[n]; //   auxiliary array to avoid creating temp array for each recursive call
    return CountInv(a, aux, 0, n-1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << CountInvMerge(arr, n) << "\n";

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////