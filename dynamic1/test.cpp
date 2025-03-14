#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    vector<vector<int>> arr(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            dp[i][j] = arr[i-1][j-1] + max(dp[i-1][j],dp[i-1][j-1]);
        }
    }


    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[m][n];
    
    return 0;   
}