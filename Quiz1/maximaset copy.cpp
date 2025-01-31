#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int x;
    int y;
}Point;

void marge(Point arr[],int l,int r,int m){
    int n1=m-l+1;
    int n2= r-m;
    Point A[n1],B[n2];
    for(int i=0;i<n1;i++){
        A[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        B[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(A[i].x<B[j].x){
            arr[k]=A[i];
            i++;
        }else{
            arr[k]=B[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=A[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=B[j];
        j++;
        k++;
    }
}

void margesort(Point arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        margesort(arr,l,m);
        margesort(arr,m+1,r);
        marge(arr,l,r,m);
    }
}

void conq(Point arr[],int l,int r,int m,vector<int> &status){
    int p;
    for(int i=m+1;i<=r;i++){
        if(status[i]==1){
            p=arr[i].y;
            break;
        }
    }
    for(int i=l;i<=m;i++){
        if(status[i]==1&&arr[i].y<p){
            status[i]=0;
        }
    }
}

void maxima(Point arr[],int l,int r,vector<int> &status){
    if(l<r){
        int m=(l+r)/2;
        maxima(arr,l,m,status);
        maxima(arr,m+1,r,status);
        conq(arr,l,r,m,status);
    }
}

int main(){
    int n;
    cin>>n;
    Point arr[n];
    vector<int> status(n,1);
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    margesort(arr,0,n-1);
    maxima(arr,0,n-1,status);
    for(int i=0;i<n;i++){
        if(status[i]==1){
            cout<<arr[i].x<<","<<arr[i].y<<" ";
        }
    }
    cout<<endl;
}
