#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bts(vector<int> &arr,int l, int r,int k){
    if (l > r){
        return -1;
    }else{
        int mid = (l+r)/2;
        if (arr[mid] == k){
            return mid;
        }else{
            if (k > arr[mid]){
                return bts(arr,mid+1,r,k);
            }else{
                return bts(arr,l,mid-1,k);
            }
        }
    }
}

int duplicateNumber(vector<int> &arr,int k){
    int idx = bts(arr,0,arr.size()-1,k);
    if (idx == -1){
        return -1;
    }
    int first,last, current;
    first = last = current = idx;
    // find first
    while (current != -1){
        first = current;
        current = bts(arr,0,current-1,k);
    }
    // find last
    current = idx;
    while (current != -1){
        last = current;
        current = bts(arr,current+1,arr.size()-1,k);
    }
    return last-first+1;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<duplicateNumber(arr,k);
    return 0;
}