#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

bool compare(int a,int b){
    return a >= b;
}

void printArr(int x[],int n){
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int x[] = {4,12,13,29,31,32,50};
    int n = sizeof(x)/sizeof(x[0]);

    sort(x,x+n,compare);

    int left = x[0];
    int right = x[1];
    int solMin = INT_MAX;

    for(int i=2;i<n;i++){
        if (right < left){
            right += x[i];
        }else{
            left += x[i];
        }
    }
    cout<<abs(left - right);

    
    return 0;
}