#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &X,vector<int> &arr,int l, int r,int k,int &sum){

    if (sum > k){
        return;
    }
    
    if (l==r){
        if (sum == k){
            for(int i=1;i<=r;i++){
                if (X[i] == 1){
                    cout<<arr[i-1]<<" ";
                }
            }
            cout<<"\n";
        }
        return;
    }

    X[l+1] = 1;
    sum += arr[l];
    solve(X,arr,l+1,r,k,sum);
    X[l+1] = 0;
    sum -= arr[l];
    solve(X,arr,l+1,r,k,sum);
}

int main(){
    int k;
    cin>>k;
    vector<int> arr(5);
    vector<int> X(5+1);
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    int sum = 0;
    solve(X,arr,0,5,k,sum);

}