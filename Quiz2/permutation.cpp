#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> &X,int start,int end,int &count){
    if (start == end-1){
        for(int i=0;i<end;i++){
            // if (X[i-1] == 1 && X[i] == 2){
            //     count++;
            // }

            // if (X[i-1] == 2 && X[i] == 1){
            //     count++;
            // }
            cout<<X[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=start;i<end;i++){
        swap(X[start], X[i]);
        permutations(X,start+1,end,count);
        swap(X[start],X[i]);
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> X(n);
    for(int i=0; i<n; i++){
        cin>>X[i];
    }

    int count = 0;

    permutations(X,0,n,count);

    cout<<count;
    

    return 0;
}