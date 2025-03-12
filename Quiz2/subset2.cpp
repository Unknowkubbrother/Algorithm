#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int>&X,int l){
    for(int i=1;i<=l;i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;
}

void subset2(vector<int> &X,int l,int r){
    printArr(X,l);
    int j = 1;
    if (l > 0){
        j = X[l] + 1;
    }

    for(int i=j;i<=r;i++){
        X[l + 1] = i;
        subset2(X,l+1,r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> X(n+1);
    subset2(X,0,n);
    return 0;
}