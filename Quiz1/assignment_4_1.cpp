#include <iostream>
#include <vector>
using namespace std;

int bts(vector<int> &arr,int l,int r,int target){
    if (l>r){
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


int duplicate(vector<int> &arr,int l,int r,int target){
    int idx = bts(arr,l,r,target);
    if (idx == -1) return -1;
    int firstIdx,currentIdx,lastIdx;
    firstIdx = currentIdx = lastIdx = idx;
    while(currentIdx != -1){
        firstIdx = currentIdx;
        currentIdx = bts(arr,l,currentIdx-1,target);
    }
    currentIdx = idx;

    while(currentIdx != -1){
        lastIdx = currentIdx;
        currentIdx = bts(arr,currentIdx+1,r,target);
    }
    
    return lastIdx-firstIdx+1;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<duplicate(arr,0,arr.size()-1,k);

    return 0;
}