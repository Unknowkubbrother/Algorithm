#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            int price = arr[i-1];
            if (i > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],price+dp[i][j-i]);
            }
        }
    }

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[n][n];

    
    return 0;
}

// 8 
// 3 5 8 9 10 17 17 20
// 8 
// 1 5 8 9 10 17 17 20