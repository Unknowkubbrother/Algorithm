#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int Vmin = INT_MAX;
    int valueI = -1;
    int valueJ = -1;

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int targetdiff = abs(k - arr[i]);
        int idxDiffTarget = bts(arr,0,n-1,targetdiff);
        if (idxDiffTarget != -1 && i != idxDiffTarget){
            int diff = abs(arr[i] - arr[idxDiffTarget]);
            if (diff < Vmin){
                Vmin = diff;
                valueJ = arr[idxDiffTarget];
                valueI = arr[i];
            }
        }
    }

    if (valueI <= valueJ){
        cout<<valueI<<" "<<valueJ;
    }else {
        cout<<valueJ<<" "<<valueI;
    }

    return 0;
}