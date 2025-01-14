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

void k_nearest(vector<int> &arr, int m,int k) {
    int idx = bts(arr, 0, arr.size() - 1, m, 0);
    int left = max(0, idx - k / 2);
    int right = min((int)arr.size() - 1, left + k - 1);
    if (right - left  <  k - 1) {
        left = max(0, right - k + 1);
    }
    printArray(arr, left, right);
}

int main() {
    vector<int> arr = {10, 12, 15, 17, 18, 20, 25};
    int k = 4;
    int m = 16;
    sort(arr.begin(), arr.end());
    k_nearest(arr,m, k);
    return 0;
}
