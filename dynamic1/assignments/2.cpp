#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int> &arr, int n, int k, vector<vector<int>> &memo) {
    if (k == 0) return true;
    if (n == 0) return false; 
    
    if (memo[n][k] != -1) return memo[n][k];

    if (k < arr[n-1]) {
        return memo[n][k] = subsetsum(arr, n-1, k, memo);
    } else {
        return memo[n][k] = subsetsum(arr, n-1, k, memo) || subsetsum(arr, n-1, k-arr[n-1], memo);
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> memo(n+1, vector<int>(k+1, -1));

    int result = subsetsum(arr, n, k, memo);

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << memo[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (result > 0){
        cout<<"T";
    }else{
        cout<<"F";
    }
    

    return 0;
}
