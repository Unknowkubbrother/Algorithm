#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int bts(vector<int> &arr,int l,int r,int target){
    if (l > r){
        return -1;
    }
    int mid = (l+r)/2;
    if (arr[mid] == target){
        return mid;
    }
    if (arr[mid] > target){
        return bts(arr,l,mid-1,target);
    }else{
        return bts(arr,mid+1,r,target);
    }

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());


    int Vmin = INT_MAX;

    for(int i=0;i<n;i++){
        int targetDiff = abs(k - arr[i]);
        int IdxTarget = bts(arr,0,arr.size()-1,targetDiff);
        if (IdxTarget != -1 && i != IdxTarget){
            int diff = abs(arr[IdxTarget] - arr[i]);
            Vmin = min(diff,Vmin);
        }
    }

    cout<<Vmin<<endl;

    return 0;
}