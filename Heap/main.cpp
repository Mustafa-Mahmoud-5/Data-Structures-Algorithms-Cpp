#include <iostream>
using namespace std;

// max heap
class BinaryHeap {
public:
    // insert in-place the element at position n and move it to the correct position by comparing it to its ancestors.
    void insert(int A[], int n) {
        int i = n;
        int val = A[n];
        // Adjust the Tree from leaf to root
        while(i > 1 && val > A[i/2]) {
            A[i] = A[i/2];
            i = i/2;
        }
        A[i] = val;
    }


    void create(int A[], int len) { // nlogN
        for(int i = 2; i < len; i++) { // loop from 2 because 1 is already the top element, and 0 is not used since we are doing 1-based idx
            insert(A, i); // logN
        }
    }

    // For Heapify, we start the in-place array from right to left
    // we ignore all the leafs (n/2)
    // we start from the last leaf's parent
    // we perform adjusting from root to bottom (up-down) for each non-leaf node like we did in deleting
    // it is unlike Creating in which we stated in-place array from left to right, we started with the last leaf, we adjusted from bottom to root

    // N is the size of the array not the last idx
    void heapify(int A[], int n){
        // # of leaf elements: (len+1)/2, index of last leaf element's parent = (len/2)-1
        for (int i=(n/2) -1 ; i>=1; i--){

            int j = 2 * i + 1;  // Left child for current i

            while(j < n-1){
                // Compare left and right children of current i
                if (A[j] < A[j+1]){
                    j = j+1;
                }

                // Compare parent and largest child
                if (A[i] < A[j]){
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    i = j;
                    j = 2 * i + 1;
                } else {
                    break;
                }
            }
        }
    }











    // NOTE: n is the last index of the array
    int remove(int A[], int n) {
        int i, j, temp, x;

        i  = 1;
        j = 2*i;
        x = A[i]; // element to remove and keep at the end
        A[i] = A[n]; // get last element
        // Adjust the tree from root to leaf
        while(j < n - 1) {
            if(A[j+1] > A[j]) {
                j = j+1;
            }
            if(A[i] < A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = i*2;
            } else {
                // A[i] is at correct position, terminate
                break;
            }
        }
        A[n] = x;
        return x;
    }

    void print(int A[], int len) {
        cout << "{ ";
        for(int i = 1; i < len; i++) {
            cout << A[i] << " ";
        }
        cout << "}" << endl;
    }

    void heapSort(int A[], int len) { // O(nlogN)
        for(int i = len-1; i >= 1; i--) { // -- o(n)
            remove(A, i); // -- O(logN)
        }
    }




};


int main() {
    BinaryHeap BH;
    int arr[] = {0, 1,2,3,4,5,6,7,8}; // 1-based idx
    int len = sizeof(arr) / sizeof(arr[0]);
    BH.heapify(arr, len);
    BH.print(arr, len);
    BH.heapSort(arr, len);
    BH.print(arr, len);
}