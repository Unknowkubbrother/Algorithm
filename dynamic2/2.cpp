#include <bits/stdc++.h>
using namespace std;

int coinChangeMemo(vector<int> &arr,int k,vector<int> &memo){
    if ( k == 0) return 0;
    if (memo[k] != 0) return memo[k];

    int minCoins = INT_MIN;
    for(int i=0;i<arr.size();i++){
        int coin = arr[i];
        if (k >= coin){
            int subProb = coinChangeMemo(arr,k-coin,memo);
            if (subProb != -1){
                minCoins = max(minCoins, 1+ subProb);
            }
        }
    }

    memo[k] = (minCoins == INT_MAX) ? -1 : minCoins;
    return memo[k];
}


int coinChangeDp(vector<int> &arr,int k){
    vector<int> dp(k+1,k);
    dp[0] = 0;

    for(int i=1;i<dp.size();i++){
        for(int j=0;j<arr.size();j++){
            int coin = arr[j];
            if (i >= coin){
                dp[i] = min(dp[i],1 + dp[i-coin]);
            }
        }
    }

    return dp[k] > k ? -1 : dp[k];
}



int main(){
    int n,k;
    cin>>k>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> memo(k+1,0);
    

    // int result = coinChangeMemo(arr,k,memo);
    // cout<<result;

    // for(int i=0;i<memo.size();i++){
        // cout<<memo[i]<<" ";
    // }

    int result = coinChangeDp(arr,k);
    cout<<result;
    

    return 0;
}