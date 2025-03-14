#include <bits/stdc++.h>
using namespace std;

long long int g(long long int n,vector<long long int> &memoG){
    if (n <= 0) return 1;
    if (n == 1) return 2;
    return memoG[n] != -1 ? memoG[n] : memoG[n] = g(n-1,memoG) + g(n-2,memoG);
}

long long int t(long long int n,vector<long long int> &memoT,vector<long long int> &memoG){
    if (n <= 0) return 1;
    return memoT[n] != -1 ? memoT[n] : memoT[n] = t(n-1,memoT,memoG) + g(n/2,memoG) + n;
}

int main(){
    int n;
    cin>>n;
    vector<long long int> memoG(n+1,-1);
    vector<long long int> memoT(n+1,-1);
    long long int result = t(n,memoT,memoG);

    cout<<result;
    return 0;
}