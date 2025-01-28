#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count = 1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if (arr[i] != arr[i-1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}