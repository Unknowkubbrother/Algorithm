#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void medainofThree(vector<int> &arr,int l,int r){
    int mid = (l+r)/2;
    if (arr[l] > arr[mid]){
        swap(arr[l],arr[mid]);
    }
    if (arr[l] > arr[mid]){
        swap(arr[l],arr[mid]);
    }
    if (arr[mid] > arr[r]){
        swap(arr[mid],arr[r]);
    }
    swap(arr[mid],arr[r]);
}

int partition(vector<int> &arr,int l,int r){
    medainofThree(arr,l,r);
    int pivot = arr[r];
    int down = l-1;
    int up = r;
    while (true){
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

int QuickSelect(vector<int> &arr,int l,int r,int k){
    if (l == r){
        return l;
    }else{
        int p = partition(arr,l,r);
        if (p - l == k - 1){
            return p;
        }else if (p-l > k - 1){
            return QuickSelect(arr,l,p-1,k);
        }else{
            k = k - (p+1);
            return QuickSelect(arr,p+1,r,k);
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int target = QuickSelect(arr,0,n-1,n-k+1);
    int sum = 0;
    int count = 0;
    for(int i=target;i<arr.size();i++){
        sum += arr[i];
    }
     cout<<fixed<<setprecision(2)<<(sum/(double)(arr.size()-target));
    return 0;
}