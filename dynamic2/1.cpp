#include <bits/stdc++.h>
using namespace std;

int C(int i,int j){
    return (2*i)+j;
}

int P(int i,int j,vector<vector<int>> &memo){
    if (i == 0) return 3*j;
    if (j == 0) return 2*i;
    return memo[i][j] != -1 ? memo[i][j] : memo[i][j] = min( min(P(i-1,j,memo)+2 , P(i,j-1,memo)+3), P(i-1,j-1,memo) + C(i,j));
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
    int result = P(n,m,memo);
    cout<<result;
    return 0;
}