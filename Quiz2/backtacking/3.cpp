#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int,int>> &arr, vector<int> &X, int l, int n, int sumW, int &sumV, int k) {
    if (sumW > k) {
        return;
    }

    int sum = 0;
    for (int i = 1; i <= l; i++) {
        sum += arr[X[i] - 1].second;
    }

    sumV = max(sumV, sum);

    int j = 1;
    if (l > 0) {
        j = X[l] + 1;
    }

    for (int i = j; i <= n; i++) {
        X[l + 1] = i;
        solve(arr, X, l + 1, n, sumW + arr[i - 1].first, sumV, k);
    }
}

int main() {
    int k;
    int n = 4;
    cin >> k;
    vector<pair<int, int>> arr(n);
    vector<int> X(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }

    int sumV = 0;
    int sumW = 0;
    solve(arr, X, 0, n, sumW, sumV, k);

    cout << sumV;

    return 0;
}