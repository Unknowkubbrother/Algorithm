#include <iostream>
#include <algorithm>
using namespace std;

void permute(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 1; i <= end; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n = 3;
    int arr[] = {-1, 1, 2, 3};

    permute(arr, 1, n);

    return 0;
}
