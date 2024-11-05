#include <iostream>
using namespace std;

bool is_in_to_the_right(const int a[],const int length,const int k, int n) {
    for (; n < length; n++) {
        if (a[n] == k) return true;
    }
    return false;
}

void print_only_once(const int a[], const int length) {
    for (int i = 0; i < length; i++) {
        if (!is_in_to_the_right(a, length, a[i], i+1)) {
            cout << a[i] << ' ';
        }
    }
}

int main() {
    constexpr int length = 10;
    const int arr[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << is_in_to_the_right(arr, length, 5, 1) << endl;
    cout << is_in_to_the_right(arr, length, 5, 6) << endl;

    const int arr2[length] = {1, 2, 4, 4, 1, 1, 1, 1, 1, 1};
    print_only_once(arr2, length);

    return 0;
}
