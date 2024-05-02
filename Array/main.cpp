#include <iostream>
#include <string>
using namespace std;

class Array {
private:
    int size; // capacity
    int length;
    int* A;
public:
    Array(int max_size) {
        size = max_size;
        length = 0;
        A = new int[size];
    }

    void print(string message) {
        cout << message << endl;
    }

    void display() {
        cout << "{ ";
        for(int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }

        cout << "}" << endl;
    }


    bool append(int val) {
        if(length == size) {
            print("Array is empty");
            return false;
        } else {
            A[length++] = val;
            return true;
        }
    }

    bool insert(int position, int val) {
        if(position < 0 || position > length) {
            print("Out of range");
            return false;
        }
        // {1,2,3,4,5} // length:5, size:5, insert(0, 50): failed as length(first empty idx after array) is equal to the size(which is the first idx after the array capacity) so, there is no more space
        if(length >= size) {
            print("Array is full");
            return false;
        }
        // or for(int i = length -1; i >= pos; i--) { A[i+1] = A[i]; } A[pos] = val; // this is easier as indexes are not confusing.
        for(int i = length; i > position; i--) {
            A[i] = A[i-1];
        }
        A[position] = val;
        length++;
        return true;
    }


    bool insertSortedAscending(int val) {
        if(length == size) {
            print("Array is full");
            return false;
        }
        int i = length;
        for(i; i > 0 && A[i-1] > val; i--) {
            A[i] = A[i-1];
        }
        A[i] = val;
        length++;
        return true;
    }


    int remove(int position) {
        if(position < 0 || position >= length) {
            print("Out of range");
            return false;
        }

        int x = A[position];
        for(int i = position; i < length - 1; i++) {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }

    int get(int position) {
        if(position < 0 || position >= length) {
            print("out of range");
            return -1;
        }

        return A[position];
    }

    bool set(int position, int val) {
        if(position < 0 || position >= length) {
            print("out of range");
            return false;
        }

        A[position] = val;
    }

    int search(int val) {
        for(int i = 0; i < length; i++) {
            if(A[i] == val) return i;
        }
        return -1;
    }

    // apply on sorted array only
    int binarySearch(int val) {
        int l = 0, r = length - 1, mid = (l + r) / 2;
        while(l <= r) {
            if(A[mid] == val) {
                return mid;
            } else if(A[mid] > val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }


    int recursiveBinarySearch(int l, int r, int val) {
        if(l > r) return -1;
        int mid = (l + r) / 2;
        if(A[mid] == val) return mid;
        if(A[mid] > val) {
            return recursiveBinarySearch(l, mid-1, val);
        } else {
            return recursiveBinarySearch(mid+1, r, val);
        }
    }


    int recursiveSum(int idx) {
        if(idx < 0 || idx >= length || length == 0) {
            return 0;
        }

        if(idx == length - 1) {
            return A[idx];
        } else {
            return A[idx] + recursiveSum(idx+1);
        }
    }

    int avg() {
        return recursiveSum(0)  / length;
    }

    bool isSortedAscendingly() {
        for(int i = 0; i < length - 1; i++) {
            if(A[i] > A[i+1]) {
                return false;
            }
        }
        return true;
    }

    // merge this array with another array and return a pointer to new array created in heap
    Array* merge(Array& arr2) {
        int p1 = 0; int p2 = 0;

        int l1 = length; int l2 = arr2.length; int l3 = l1 + l2;

        Array* arr3 = new Array(l3);



        while(p1 < l1 && p2 < l2) {
            if(A[p1] < arr2.A[p2]) {
                arr3->append(A[p1++]);
            } else {
                arr3->append(arr2.A[p2++]);
            }
        }

        for(p1; p1 < l1; p1++) {
            arr3->append(A[p1]);
        }

        for(p2; p2 < l2; p2++) {
            arr3->append(arr2.A[p2++]);
        }

        return arr3;
    }

    void arrangeNegativePositive() {
        int p[length];
        int n[length];
        int pIdx = 0;
        int nIdx = 0;

        for(int i = 0; i < length - 1; i++) {
            if(A[i] < 0) {
                n[nIdx++] = A[i];
            } else {
                p[pIdx++] = A[i];
            }
        }

        int j = 0;;
        for(int i = 0; i < nIdx; i++) {
            A[j++] = A[i];
        }

        for(int i = 0; i < pIdx; i++) {
            A[j++] = A[i];
        }
    }
};



int main() {
    Array arr(5);
    arr.append(3);
    arr.append(5);
    arr.append(10);
    arr.append(12);
    arr.display();
    arr.insert(0, 50);
    arr.display();
    arr.remove(0);
    arr.display();
    arr.remove(3);
    arr.display();


    cout << arr.recursiveSum(0) << endl;
    cout << arr.avg() << endl;


    Array arr2(5);
    arr2.insertSortedAscending(10);
    arr2.insertSortedAscending(3);
    arr2.insertSortedAscending(7);
    arr2.insertSortedAscending(1);
    arr2.insertSortedAscending(0);
    arr2.display();
    cout << arr2.recursiveBinarySearch(0, 4,  7) << endl;

    Array arr3(5);
    arr3.insertSortedAscending(10);
    arr3.insertSortedAscending(7);
    arr3.insertSortedAscending(8);
    arr3.insertSortedAscending(2);
    arr3.insertSortedAscending(4);
    arr3.display();

    Array* mergedArr = arr2.merge(arr3);
    mergedArr->display();

    return 0;
}
