#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> dp(k+1,k);
    dp[0] = 0;

    for(int i=1;i<dp.size();i++){
        for(int j=0;j<n;j++){
            int price = arr[j];
            if (i >= price){
                dp[i] = min(dp[i],1+dp[i-price]);
            }
        }
    }

    cout<<dp[k];

    return 0;

}