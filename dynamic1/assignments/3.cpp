#include <bits/stdc++.h>
using namespace std;

int F(int n,int k,vector<vector<int>> &memo){
    if (k < 2 || n == k) return 1;
    return memo[n][k] != -1 ? memo[n][k] : memo[n][k] = F(n-1,k,memo) + F(n-1,k-2,memo);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
    cout<<F(n,k,memo);
    return 0;
}