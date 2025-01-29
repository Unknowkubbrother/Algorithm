#include <iostream>
#include <vector>
using namespace std;

void interpolation(vector<int> &arr,int l,int r,int target){
    if (l > r){
        return;
    }
    int mid = l + ((target - arr[l])*(r-l)/(arr[r]-arr[l]));
    cout<<mid<<" ";
    if (arr[mid] == target){
        return;
    }
    if (arr[mid] > target){
        return interpolation(arr,l,mid-1,target);
    }else{
        return interpolation(arr,mid+1,r,target);
    }
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    interpolation(arr,0,arr.size()-1,target);
    return 0;
}