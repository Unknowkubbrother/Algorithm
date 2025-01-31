#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxCrossingSum(const vector<int>& prices, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += prices[i];
        leftSum = max(leftSum,sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += prices[i];
        rightSum = max(rightSum,sum);
    }

    return leftSum + rightSum;
}

int maxSubArraySum(const vector<int>& prices, int low, int high) {
    if (low == high) {
        return prices[low];
    }

    int mid = (low + high) / 2;

    int leftMax = maxSubArraySum(prices, low, mid);
    int rightMax = maxSubArraySum(prices, mid + 1, high);
    int crossMax = maxCrossingSum(prices, low, mid, high); 

    return max(max(leftMax,rightMax),crossMax);
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int maxProfit = maxSubArraySum(prices, 0, n - 1);
    cout << maxProfit << endl;

    return 0;
}