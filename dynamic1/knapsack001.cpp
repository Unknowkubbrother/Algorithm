#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            int weight = arr[i-1].second;
            int value = arr[i-1].first;

            if (weight > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],value+dp[i-1][j-weight]);
            }

        }
    }

    cout<<dp[n][k];

    return 0;
}