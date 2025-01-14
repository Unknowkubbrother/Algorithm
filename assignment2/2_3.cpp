#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int bts(vector<int> &arr,int l,int r,int m, int closetIdx){
    if (l > r) {
        return closetIdx;
    }
    int mid = (l + r) / 2;
    if (arr[mid] == m) {
        return mid;
    }else if (abs((arr[mid] - m)) < abs(arr[closetIdx] - m)) {
        closetIdx = mid;
    }
    if (arr[mid] > m) {
        return bts(arr, l, mid - 1, m, closetIdx);
    }else{
        return bts(arr, mid + 1, r, m, closetIdx);
    }
}

void printArray(vector<int> &arr,int left,int right){
    for(int i=left;i<=right;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void k_nearest(vector<int> &arr,int m,int k){
    int i = bts(arr, 0, arr.size() - 1, m, 0);
    int left = i-1, right = i;
    while((right - left - 1) < k){
        cout<<left<<" "<<right<<endl;
        if (left < 0) {
            right = right + 1;
        }else if (right == arr.size()) {
            left = left - 1;
        }else if (abs(arr[left] - m) > abs(arr[right] - m)) {
            right = right + 1;
        }else if (abs(arr[left] - m) <= abs(arr[right] - m)) {
            left = left - 1;
        }
    }
    printArray(arr,left+1,right-1);
}

int main(){
    vector<int> arr = {10,12,15,17,18,20,25};
    int k= 4;
    int m = 16;
    sort(arr.begin(),arr.end());
    k_nearest(arr,m,k);
    return 0;
}