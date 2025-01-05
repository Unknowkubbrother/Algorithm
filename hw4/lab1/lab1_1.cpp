#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr,int l, int m,int r){
    int nL = m-l+1;
    int nR = r-m;
    vector<int> L(nL);
    vector<int> R(nR);

    for(int i=0;i<nL;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<nR;j++){
        R[j] = arr[m+1+j];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<nL && j<nR){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        }else{
            arr[k] = R[j++];
        }
        k++;
    }

    while(i<nL || j < nR){
        if (i < nL){
            arr[k] = L[i++];
        }else if (j < nR){
            arr[k] = R[j++];
        }
        k++;
    }

}

void mergeSort(vector<int> &arr,int l,int r){
    if (l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int ConCount(vector<int> &arr){
    int sequenceCount = 0;
    mergeSort(arr,0,arr.size()-1);

    for(int i=1;i<=arr.size();i++){
        if (abs(arr[i] - arr[i-1]) > 1){
            sequenceCount++;
        }
    }

    return sequenceCount;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    cout<<ConCount(arr)<<endl;

    return 0;
}

// 8
// 2 57 98 3 32 78 9 12

// 10
// 2 3 5 6 10 9 4 106 102 101