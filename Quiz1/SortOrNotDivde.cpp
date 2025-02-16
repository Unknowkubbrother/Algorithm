#include <iostream>
#include <vector>
using namespace std;


bool isSorted(vector<int> &arr, int l, int r) {
    if (l == r) {
        return true;
    }
    int mid = l + (r - l) / 2;
    if (arr[mid] > arr[mid + 1]) {
        return false;
    }
    int left = isSorted(arr, l, mid);
    int right = isSorted(arr, mid + 1, r);
    return left && right;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<< isSorted(arr,0,n-1);
    return 0;
}