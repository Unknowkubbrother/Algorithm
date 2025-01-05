#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];
    int down = l;
    int up = r-1;
    while(down <= up){
        if(arr[down] < pivot){
            down++;
        }else if(arr[up] > pivot){
            up--;
        }else{
            swap(arr[up], arr[down]);
            down++;
            up--;
        }
    }
    swap(arr[down], arr[r]);
    return down;
}

void quickSort(vector<int> &arr, int l, int r){
    if(r-l > 0){
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// 9
// 551 220 551 912 81 32 745 613 109