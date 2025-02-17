#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(int a,int b){
    return a >= b;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end(),compare);

    int l,r;
    l = r = 0;

    for(int i=0;i<n;i++){
        if (l <= r){
            l+=arr[i];
        }else{
            r+=arr[i];
        }
    }

    cout<<abs(l-r);

    return 0;
}