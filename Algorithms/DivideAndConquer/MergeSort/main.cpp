#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class Type>
void PrintArr(Type* arr, int size) {
    for(int i = 0;i < size; i++) {
        cout << "(" << arr[i].x << "," << arr[i].y << ") ";
    }
    cout << endl;
}

bool IsBefore(int a, int b) {
    return a < b;
}

// Implementation A (using Auxiliary array to avoid creating the array for each merge function call)
template<class Type>
void Merge(Type* arr, Type* aux, int l, int m, int h, bool (*IsBefore)(Type& a, Type& b)) {
    for(int k = l; k <= h; k++) { // copy the array we want to merge into the auxiliary array
        aux[k] = arr[k];
    }

    int i = l;
    int j = m+1;
    for(int k = l; k<=h; k++) {
        if(i > m) { // if left is excausted, copy the right
            arr[k] = aux[j++];
        } else if(j > h) { // if right is excausted, copy the left
            arr[k] = aux[i++];
        } else if(IsBefore(aux[i], aux[j])) { // assuming IsBefore is a function that returns true if a < b. then copy the left, else copy the right
            arr[k] = aux[i++];
        } else {
            arr[k] = aux[j++];
        }
    }
}

template<class Type>
void MergeSort(Type* arr, Type* aux, int l, int h, bool (*IsBefore)(Type& a, Type& b)) {
    if(l < h) {
        int mid = l + (h - l) / 2;
        MergeSort(arr, aux, l, mid, IsBefore);
        MergeSort(arr, aux, mid+1, h, IsBefore);
        Merge(arr, aux, l, mid, h, IsBefore);
        // According to Master Theorem.., T(n) = 2T(n/2) + O(n) => O(nlogn)
    }
}
template<class Type>
void Sort(Type* arr, int n, bool (*IsBefore)(Type& a, Type& b)) {
    Type aux[n]; // the array we're going to copy the two arrays we want to merge into
    MergeSort(arr, aux, 0, n-1, IsBefore);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    Sort(arr, n, IsBefore);
}