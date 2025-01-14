#include <iostream>
#include <vector>
using namespace std;


void medianOfThree(vector<int> &arr, int l, int r) {
    int mid = (l + r) / 2;
    if (arr[l] > arr[mid])
        swap(arr[l], arr[mid]);
    if (arr[l] > arr[r])
        swap(arr[l], arr[r]);
    if (arr[mid] > arr[r])
        swap(arr[mid], arr[r]);
    swap(arr[mid], arr[r]);
}

int partition(vector<int> &arr, int l, int r) {
    medianOfThree(arr, l, r);
    int pivot = arr[r];
    int down = l - 1;
    int up = r;
    while(true){
        do{
            ++down;
        }while(arr[down]< pivot);
        do{
            --up;
        }while(arr[up]>pivot);
        if (down >= up){
            break;
        }
        swap(arr[down], arr[up]);
    }
    swap(arr[down], arr[r]);
    return down;
}

int quickSelect(vector<int> &arr,int l,int high,int k){
    if (l == high){
        return arr[l];
    }
    int p = partition(arr,l,high);
    if (p-l == k-1){
        return arr[p];
    }else if (p-l > k-1){
        return quickSelect(arr,l,p-1,k);
    }else{
        k = k - (p+1);
        return quickSelect(arr,p+1,high,k);
    }
}

int main(){
    vector<int> arr = {1,5,10,4,8,2,6,9,20};
    int k = 4;
    cout<<quickSelect(arr,0,arr.size()-1,k);
    return 0;
}
