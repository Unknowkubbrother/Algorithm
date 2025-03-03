#include <bits/stdc++.h>
using namespace std;

long long int f(long long int n,vector<long long int> &memo){
    if (n < 2) return n;
    return memo[n] ? memo[n] : memo[n] = f(n-2,memo)+f(n-1,memo);
}

int main(){
    long long int n;
    cin>>n;
    vector<long long int> memo(n+1,0);
    vector<long long int> dp(n);

    dp[0] = 0;
    dp[1] = 1;
    long long int sum = 0;
    for(long long int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
    // cout<<f(n,memo);


    return 0;
}