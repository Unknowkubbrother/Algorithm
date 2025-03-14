#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &X,vector<int> &arr,int l,int n,int k,vector<int> &result) {
    if (l > 3) return;
    if (result.size() == 3) return;
    int sum = 0;
    for(int i=1;i<=l;i++){
        sum += arr[X[i]-1];
    }
    if (sum == k && l == 3){
        for(int i=1;i<=l;i++){
            result.push_back(arr[X[i]-1]);
            // cout<<arr[X[i]-1]<<" ";
        }
        // cout<<"size "<<result.size();
    }


    int j = 1;
    if (l > 0){
        j = X[l] + 1;
    }

    for(int i=j;i<=n;i++){
        X[l + 1] = i;
        solve(X,arr,l+1,n,k,result); 
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> X(n+1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result;
    solve(X,arr,0,n,k,result);

    sort(result.begin(),result.end());

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}

// 8 600  
// 136  
// 411  
// 211  
// 200 
// 275  
// 189  
// 232  
// 375
