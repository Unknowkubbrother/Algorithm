#include <bits/stdc++.h>
using namespace std;

int main(){
    int wt,n;
    cin>>wt>>n;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        arr[i].first = value;
    }

    for(int i=0;i<n;i++){
        int weight;
        cin>>weight;
        arr[i].second = weight;
    }

    vector<vector<int>> dp(arr.size()+1,vector<int>(wt+1,0));

    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            int weight = arr[i].second;
            int value = arr[i].first;

            if (weight > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(value + dp[i-1][j - weight], dp[i-1][j]);
            }
        }
    }    

    // for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<dp[i].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][n];

    
    
    return 0;
}

// 10 4
// 10 40 30 50
// 5 4 6 3