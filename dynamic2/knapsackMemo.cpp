#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<pair<int,int>> &arr,int i,int j,vector<vector<int>> &memo){
    if (i == 0) return 0;
    if (j == 0) return 0;

    if (memo[i][j] != 0) return memo[i][j];

    int weight = arr[i-1].second;
    int value = arr[i-1].first;

    int exclude = knapsack(arr,i-1,j,memo);
    int include = 0;
    if (weight <= j){
        include = value + knapsack(arr,i-1,j - weight,memo);
    }
    

    memo[i][j] = max(exclude,include);
    return memo[i][j];
}

int main(){
    int wt,n;
    cin>>wt>>n;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        arr[i].first = value;
    }

    for(int i=0;i<n;i++){
        int weight;
        cin>>weight;
        arr[i].second = weight;
    }

    vector<vector<int>> memo(arr.size()+1,vector<int>(wt+1,0));


    int result = knapsack(arr,n,wt,memo);

    for(int i=0;i<memo.size();i++){
        for(int j=0;j<memo[i].size();j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<result;

    
    
    return 0;
}

// 10 4
// 10 40 30 50
// 5 4 6 3