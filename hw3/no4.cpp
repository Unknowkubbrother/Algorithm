#include <iostream>
using namespace std;

int sum(int *arr,int n){
    if (n > 1){
        return arr[n-1] + sum(arr,n-1);
    }else {
        return arr[0];
    }
}

int main(){
    int *arr;
    int n;
    cin>>n;
    arr = new int[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<sum(arr,n)<<endl;
    
    return 0;
}