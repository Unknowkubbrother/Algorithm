#include <iostream>
#include <vector>
using namespace std;


void printArr(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &arr,int l,int m,int r){
    int nL = m-l+1;
    int nR = r-m;
    vector<int> L(nL);
    vector<int> R(nR);
     
    for(int i=0;i<nL;i++){
        L[i] = arr[l+i]; 
    }

    for(int i=0;i<nR;i++){
        R[i] = arr[m+i+1];
    }

    int i,j;
    i=j=0;
    int k = l;

    while(i < nL && j < nR){
        if (L[i] <= R[j]){
            arr[k] = L[i++];
        }else {
            arr[k] = R[j++];
        }
        k++;
    }

    while(i<nL||j<nR){
        if (i<nL){
            arr[k] = L[i++];
        }else{
            arr[k] = R[j++];
        }
        k++;
    }
}


void mergeSort(vector<int> &arr,int l,int r){
    if (l >= r){
        return;
    }
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    printArr(arr);
    return 0;
}