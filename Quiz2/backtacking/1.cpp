#include <bits/stdc++.h>
using namespace std;

void sovle(vector<int> &arr,int start,int end,int &count){
    if (start == end-1){
        for(int i=1;i<end-1;i++){
            if ((arr[i-1] == 1 && arr[i] == 2 && arr[i+1] == 3) || 
            (arr[i-1] == 3 && arr[i] == 2 && arr[i+1] == 1)){
            count++;        
            }
        }
    }

    for(int i=start;i<end;i++){
        swap(arr[i],arr[start]);
        sovle(arr,start+1,end,count);
        swap(arr[i],arr[start]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=1;i<=n;i++){
        arr[i-1] = i;
    }

    // int count = 0;
    // sovle(arr,0,n,count);
    // cout<<count;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    cout<<dp[n-3] * dp[4];


    return 0;
}