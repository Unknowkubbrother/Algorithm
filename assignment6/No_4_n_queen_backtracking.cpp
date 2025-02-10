#include <iostream>
#include <cmath>
using namespace std;

int solutionCount = 0;

bool isSafe(int arr[], int start) {
    for (int p = 1; p < start; p++) {
        if ((abs(p - start) == abs(arr[p] - arr[start])) || (arr[start] == arr[p])) {
            return false;
        }
    }
    return true;
}

void permute(int arr[], int start, int end) {
    if (start == end + 1) {
        for (int i = 1; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        solutionCount++;
        if (isSafe(arr, start)) {
            permute(arr, start + 1, end);
        }
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n = 16;
    int arr[] = {-1, 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15};

    permute(arr, 1, n);
    cout << "Total solutions: " << solutionCount << endl;

    return 0;
}
