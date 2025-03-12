#include <bits/stdc++.h>
using namespace std;

void sovle(vector<int> &arr,int start,int end,int &count){
    if (start == end-1){
        for(int i=1;i<end;i++){
            if (arr[i-1] == 1 && arr[i] == 2){
                count++;        
            }

            if (arr[i-1] == 2 && arr[i] == 1){
                count++;
            }
        }
    }

    for(int i=start;i<end;i++){
        swap(arr[i],arr[start]);
        sovle(arr,start+1,end,count);
        swap(arr[i],arr[start]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=1;i<=n;i++){
        arr[i] = i;
    }

    int count = 0;
    sovle(arr,0,n,count);
    cout<<count;

    return 0;
}