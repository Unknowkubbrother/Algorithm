#include <iostream>
#include <vector>
using namespace std;

bool SortOrNot(vector<int> &arr, int n, int before){
    if (n == 0){
        return true;
    }
    int sort = arr[n] <= arr[before];
     before = n;
    return sort ? SortOrNot(arr,n-1,before) : false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if (SortOrNot(arr,arr.size()-2,arr.size()-1)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}