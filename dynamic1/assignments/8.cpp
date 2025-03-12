#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n, int k, vector<vector<int>> &memo) {
    if (k == 0) return 0;
    if (n == 0) return 0;
    if (memo[n][k] != -1) return memo[n][k];

    int exclude = solve(arr, n-1, k, memo);
    int include = 0;
    if (arr[n-1] <= k) {
        include = 1 + solve(arr, n-1, k-arr[n-1], memo);
    }

    memo[n][k] = max(include, exclude);
    return memo[n][k];
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
    int result = solve(arr,n,k,memo);
    cout<<result<<endl;

    return 0;
}
