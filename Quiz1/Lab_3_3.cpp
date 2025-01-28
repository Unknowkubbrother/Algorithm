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

int partition(vector<int> &arr, int l, int r){
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
        if (up <= down) {
            break;
        }
        swap(arr[down],arr[up]);
    }
    swap(arr[down],arr[r]);
    return down;
}

int quickselect(vector<int> &arr, int l, int r, int k){
    if (l == r){
        return arr[l];
    }else{
        int p = partition(arr,l,r);
        if (p-l == k-1){
            return arr[p];
        }else if (p-l > k-1){
            return quickselect(arr,l,p-1,k);
        }else{
            k = k - (p+1);
            return quickselect(arr,p+1,r,k);
        }
    }
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int count = 0;
    int result = quickselect(arr, 0, arr.size()-1, k);
    for(int i=0;i<n;i++){
        count++;
        if (arr[i] == result){
            break;
        }
    }
    cout<<result<<" "<<count;
    return 0;
}