#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>k>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(k+1, INT_MAX));
    dp[0][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if (j == 0) {
                dp[i][j] = 0;
            } else if (arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-arr[i-1]]);
            }
        }
    }

    cout<<dp[n][k];

    
    return 0;
}