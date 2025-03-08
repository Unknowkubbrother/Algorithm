#include <bits/stdc++.h>
using namespace std;

long long int G(int n, vector<long long int> &memo){
    if (n == 0) return 0;
    if ( n == 1 || n == 2) return 1;
    return memo[n] != -1 ? memo[n] : memo[n] = G(n-1,memo) + G(n-2,memo) - G(n-3,memo);
}

int main(){
    int n;
    cin>>n;
    vector<long long int> memo(n+1,-1);

    cout<<G(n,memo);
    return 0;
}