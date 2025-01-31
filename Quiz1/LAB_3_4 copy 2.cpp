#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cur=0;
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(cur<0){
            cur=0;
        }
        cur+=arr[i];
        if(cur>max){
            max=cur;
        }
    }
    cout<<max<<endl;
}