#include <iostream>
#include <vector>
using namespace std;

void medianofThree(vector<int> &arr,int l,int r){
    int mid = (l+r)/2;
    if (arr[l] > arr[mid]){
        swap(arr[l],arr[mid]);
    }
    if (arr[l] > arr[r]){
        swap(arr[l],arr[r]);
    }
    if (arr[mid] > arr[r]){
        swap(arr[mid],arr[r]);
    }
    swap(arr[mid],arr[r]);
}


int partition(vector<int> &arr,int l,int r){
    medianofThree(arr,l,r);
    int pivot = arr[r];
    int down = l-1;
    int up = r;
    while(true){
        do{
            down++;
        }while(arr[down] < pivot);
        do{
            up--;
        }while(arr[up] > pivot);
        if (up <= down){
            break;
        }
        swap(arr[down],arr[up]);
    }
    swap(arr[down],arr[r]);
    return down;
}


void QuickSort(vector<int> &arr,int l,int r){
    if (r - l > 0){
        int p = partition(arr,l,r);
        QuickSort(arr,l,p - 1);
        QuickSort(arr,p+1,r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }
    QuickSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}