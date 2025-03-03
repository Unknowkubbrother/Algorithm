#include <bits/stdc++.h>
using namespace std;

long long int cnk(long long int n,long long int k,vector<vector<long long int>> &memo){
    if (k==0) return 1;
    if (n == k) return 1;
    return memo[n][k] ? memo[n][k] : memo[n][k] = cnk(n-1,k-1,memo) + cnk(n-1,k,memo);
}

int min(int a,int b){
    return a < b ? a : b;
}


int main(){
    long long int n,k;
    cin>>n>>k;
    vector<vector<long long int>> memo(n+1,vector<long long int>(k+1,0));

    // cout<<cnk(n,k,memo);

    vector<vector<long long int>> dp(n+1,vector<long long int>(k+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j=1;j<= min(i,k);j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    cout<<dp[n][k];
    return 0;
}