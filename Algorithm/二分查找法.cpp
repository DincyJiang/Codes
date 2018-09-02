#include <iostream>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (arr[mid] == target) {
            return mid;
        }
        if (target > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    
}

