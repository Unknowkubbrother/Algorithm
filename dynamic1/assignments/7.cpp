#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m, vector<vector<int>> &memo){
    if (n == 1 && m == 1) return 1;
    if (n < 0 || m < 0) return 0;
    return memo[n][m] != -1 ? memo[n][m] : memo[n][m] = solve(n,m-1,memo) + solve(n-1,m,memo);
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
    cout<<solve(n,m,memo);
    return 0;
}