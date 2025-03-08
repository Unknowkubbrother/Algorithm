#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return (a.second - a.first) > (b.second - b.first);
}

int findMaxActivity(vector<pair<int,int>> &arr,int k){
    queue<pair<int,int>> room[k];
    int Activity = 0;

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<k;j++){
            if (room[j].empty() || room[j].back().second <= arr[i].first){
                room[j].push(arr[i]);
                Activity++;
                break;
            }
        }
    }

    return Activity;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin(),arr.end(),compare);

    int amount = findMaxActivity(arr,k);

    cout<<amount;

    return 0;
}