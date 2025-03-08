#include <bits/stdc++.h>
using namespace std;

int find(int n,vector<int> &memo){
    if (n == 0 || n == 1) return 1;
    return memo[n] != -1 ? memo[n] : memo[n] = 3*find(n-1,memo) + 2*find(n-2,memo);
}

int main(){
    int n;
    cin>>n;
    vector<int> memo(n+1,-1);
    cout<<find(n,memo);
    return 0;
}