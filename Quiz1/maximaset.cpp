#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int x;
    int y;
} Point;

void printArr(vector<Point> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<"("<<arr[i].x<<","<<arr[i].y<<") ";
    }
    cout<<endl;
}

void printArrStatus(vector<int> &status,vector<Point> &arr){
    for(int i=0;i<status.size();i++){
        if (status[i] == 1){
            cout<<"("<<arr[i].x<<","<<arr[i].y<<") ";
        }
    }
    cout<<endl;
}

void merge(vector<Point> &arr,int l,int m,int r){
    int nL = m-l+1;
    int nR = r-m;
    vector<Point> L(nL);
    vector<Point> R(nR);

    for(int i=0;i<nL;i++){
        L[i] = arr[l+i];
    }

    for(int i=0;i<nR;i++){
        R[i] = arr[m+i+1];
    }


    int i,j,k;
    i = j = 0;
    k = l;
    while(i < nL && j <nR){
        if (L[i].x <= R[j].x){
            arr[k] = L[i++];
        }else{
            arr[k] = R[j++];
        }
        k++;
    }

    while(i < nL || j < nR){
        if (i < nL){
            arr[k] = L[i++];
        }else{
             arr[k] = R[j++];
        }
        k++;
    }
}

void mergeSort(vector<Point> &arr,int l,int r){
    if (l >= r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void conq(vector<Point> &arr,int l,int m,int r,vector<int> &status){
    int point = -1;
    for(int i=m+1;i<=r;i++){
        if (status[i] == 1){
            point = arr[i].y;
            break;
        }
    }

    for(int i=l;i<=m;i++){
        if (status[i] == 1 && arr[i].y < point){
            status[i] = 0;
        }
    }
}

void maximaset(vector<Point> &arr,int l, int r,vector<int> &status){
    if (l >= r){
        return;
    }
    int mid = (l+r)/2;
    maximaset(arr,l,mid,status);
    maximaset(arr,mid+1,r,status);
    conq(arr,l,mid,r,status);
}

int main(){
    int n;
    cin>>n;
    vector<Point> arr(n);
    vector<int> status(n,1);

    for(int i=0;i<arr.size();i++){
        cin>>arr[i].x>>arr[i].y;
    }

    mergeSort(arr,0,n-1);
    maximaset(arr,0,n-1,status);
    printArr(arr);
    printArrStatus(status,arr);
    return 0;
}

// 4
// 3 4 5 2 4 6 6 1

// 5
// 10 7 15 9 8 6 12 8 9 9